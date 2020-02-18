#!/usr/bin/env python

from itertools import product


class Instruction(object):
    def __init__(self, time, weight, code):
        self.time = time
        self.weight = weight
        self.code = code

instructions = [
    Instruction(4, 1, 'nop'),
    Instruction(7, 2, 'or 0'),

    # destroys A, alternative: ld i,a; ld r,a
    #Instruction(9, 2, 'ld a,r'),

    Instruction(10, 3, 'jp NEXT'),

    # Can have side effects
    #Instruction(11, 2, 'in a,(0)'),

    Instruction(12, 2, 'jr NEXT'),

    # Possibly problematic if reading/writing HL has side effects
    #Instruction(22, 2, 'inc (hl):dec (hl)'),

    # Requires SP to be writable
    #Instruction(38, 2, 'ex (sp),hl:ex (sp),hl'),
]

max_cycles = 300

solutions = [[] for _ in range(max_cycles + 1)]

max_instructions = [
    max_cycles // instr.time
    for instr in instructions
]
print 'max instructions;'
print '\n'.join(
    '%s cycles * %s = %s' % (instructions[i].time, max_instructions[i], instructions[i].time * max_instructions[i])
    for i in range(len(max_instructions))
)

print 'max_instructions', max_instructions
candidates = list(product(*[range(m + 1) for m in max_instructions]))
print 'Number of candidate combinations:', len(candidates)

for counts in candidates:
    total_cycles = sum(instructions[i].time * counts[i] for i in range(len(instructions)))
    if total_cycles <= max_cycles:
        solutions[total_cycles].append(counts)

print 'Done generating solutions'

out = open('sleep.inc', 'w')

out.write('sleep_0 MACRO\n\tENDM\n\n')

label_number = 0
for wanted_cycles in range(7, max_cycles + 1):
    #print
    #print wanted_cycles, 'cycles:'
    if not solutions[wanted_cycles]:
        out.write('; No way to sleep %s cycles\n\n' % wanted_cycles)
        print 'NO SOLUTION TO', wanted_cycles
        continue

    #print 'solutions for', wanted_cycles, ':', solutions[wanted_cycles]
    best_solution = None
    best_weight = None
    for solution in solutions[wanted_cycles]:
        weight = sum(instructions[i].weight * count for i, count in enumerate(solution))
        #print 'Solution with weight', weight
        if best_solution is None or weight < best_weight:
            best_solution = solution
            best_weight = weight
    out.write('sleep_%s MACRO\n' % wanted_cycles)
    for i, count in enumerate(best_solution):
        instr = instructions[i]
        comment = '%st, %s bytes' % (instr.time, instr.weight)
        for _ in range(count):
            #print instr.code, ';', instr.time, 'cycles', instr.weight, 'bytes'
            if 'NEXT' in instr.code:
                label = '.j%04d\@' % label_number
                label_number += 1
                out.write('\t%s ; %s\n' % (
                    instr.code.replace('NEXT', label), comment
                ))
                out.write(label + ':\n')
            else:
                out.write('\t' + instr.code + '\n')

    out.write('\tENDM\n\n')

print 'Done'
