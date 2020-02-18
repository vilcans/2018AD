sleep_0 MACRO
	ENDM

sleep_7 MACRO
	or 0
	ENDM

sleep_8 MACRO
	nop
	nop
	ENDM

; No way to sleep 9 cycles

sleep_10 MACRO
	jp .j0000\@ ; 10t, 3 bytes
.j0000\@:
	ENDM

sleep_11 MACRO
	nop
	or 0
	ENDM

sleep_12 MACRO
	jr .j0001\@ ; 12t, 2 bytes
.j0001\@:
	ENDM

; No way to sleep 13 cycles

sleep_14 MACRO
	or 0
	or 0
	ENDM

sleep_15 MACRO
	nop
	nop
	or 0
	ENDM

sleep_16 MACRO
	nop
	jr .j0002\@ ; 12t, 2 bytes
.j0002\@:
	ENDM

sleep_17 MACRO
	or 0
	jp .j0003\@ ; 10t, 3 bytes
.j0003\@:
	ENDM

sleep_18 MACRO
	nop
	or 0
	or 0
	ENDM

sleep_19 MACRO
	or 0
	jr .j0004\@ ; 12t, 2 bytes
.j0004\@:
	ENDM

sleep_20 MACRO
	nop
	nop
	jr .j0005\@ ; 12t, 2 bytes
.j0005\@:
	ENDM

sleep_21 MACRO
	or 0
	or 0
	or 0
	ENDM

sleep_22 MACRO
	jp .j0006\@ ; 10t, 3 bytes
.j0006\@:
	jr .j0007\@ ; 12t, 2 bytes
.j0007\@:
	ENDM

sleep_23 MACRO
	nop
	or 0
	jr .j0008\@ ; 12t, 2 bytes
.j0008\@:
	ENDM

sleep_24 MACRO
	jr .j0009\@ ; 12t, 2 bytes
.j0009\@:
	jr .j0010\@ ; 12t, 2 bytes
.j0010\@:
	ENDM

sleep_25 MACRO
	nop
	or 0
	or 0
	or 0
	ENDM

sleep_26 MACRO
	or 0
	or 0
	jr .j0011\@ ; 12t, 2 bytes
.j0011\@:
	ENDM

sleep_27 MACRO
	nop
	nop
	or 0
	jr .j0012\@ ; 12t, 2 bytes
.j0012\@:
	ENDM

sleep_28 MACRO
	nop
	jr .j0013\@ ; 12t, 2 bytes
.j0013\@:
	jr .j0014\@ ; 12t, 2 bytes
.j0014\@:
	ENDM

sleep_29 MACRO
	or 0
	jp .j0015\@ ; 10t, 3 bytes
.j0015\@:
	jr .j0016\@ ; 12t, 2 bytes
.j0016\@:
	ENDM

sleep_30 MACRO
	nop
	or 0
	or 0
	jr .j0017\@ ; 12t, 2 bytes
.j0017\@:
	ENDM

sleep_31 MACRO
	or 0
	jr .j0018\@ ; 12t, 2 bytes
.j0018\@:
	jr .j0019\@ ; 12t, 2 bytes
.j0019\@:
	ENDM

sleep_32 MACRO
	nop
	nop
	jr .j0020\@ ; 12t, 2 bytes
.j0020\@:
	jr .j0021\@ ; 12t, 2 bytes
.j0021\@:
	ENDM

sleep_33 MACRO
	or 0
	or 0
	or 0
	jr .j0022\@ ; 12t, 2 bytes
.j0022\@:
	ENDM

sleep_34 MACRO
	jp .j0023\@ ; 10t, 3 bytes
.j0023\@:
	jr .j0024\@ ; 12t, 2 bytes
.j0024\@:
	jr .j0025\@ ; 12t, 2 bytes
.j0025\@:
	ENDM

sleep_35 MACRO
	nop
	or 0
	jr .j0026\@ ; 12t, 2 bytes
.j0026\@:
	jr .j0027\@ ; 12t, 2 bytes
.j0027\@:
	ENDM

sleep_36 MACRO
	jr .j0028\@ ; 12t, 2 bytes
.j0028\@:
	jr .j0029\@ ; 12t, 2 bytes
.j0029\@:
	jr .j0030\@ ; 12t, 2 bytes
.j0030\@:
	ENDM

sleep_37 MACRO
	nop
	or 0
	or 0
	or 0
	jr .j0031\@ ; 12t, 2 bytes
.j0031\@:
	ENDM

sleep_38 MACRO
	or 0
	or 0
	jr .j0032\@ ; 12t, 2 bytes
.j0032\@:
	jr .j0033\@ ; 12t, 2 bytes
.j0033\@:
	ENDM

sleep_39 MACRO
	nop
	nop
	or 0
	jr .j0034\@ ; 12t, 2 bytes
.j0034\@:
	jr .j0035\@ ; 12t, 2 bytes
.j0035\@:
	ENDM

sleep_40 MACRO
	nop
	jr .j0036\@ ; 12t, 2 bytes
.j0036\@:
	jr .j0037\@ ; 12t, 2 bytes
.j0037\@:
	jr .j0038\@ ; 12t, 2 bytes
.j0038\@:
	ENDM

sleep_41 MACRO
	or 0
	jp .j0039\@ ; 10t, 3 bytes
.j0039\@:
	jr .j0040\@ ; 12t, 2 bytes
.j0040\@:
	jr .j0041\@ ; 12t, 2 bytes
.j0041\@:
	ENDM

sleep_42 MACRO
	nop
	or 0
	or 0
	jr .j0042\@ ; 12t, 2 bytes
.j0042\@:
	jr .j0043\@ ; 12t, 2 bytes
.j0043\@:
	ENDM

sleep_43 MACRO
	or 0
	jr .j0044\@ ; 12t, 2 bytes
.j0044\@:
	jr .j0045\@ ; 12t, 2 bytes
.j0045\@:
	jr .j0046\@ ; 12t, 2 bytes
.j0046\@:
	ENDM

sleep_44 MACRO
	nop
	nop
	jr .j0047\@ ; 12t, 2 bytes
.j0047\@:
	jr .j0048\@ ; 12t, 2 bytes
.j0048\@:
	jr .j0049\@ ; 12t, 2 bytes
.j0049\@:
	ENDM

sleep_45 MACRO
	or 0
	or 0
	or 0
	jr .j0050\@ ; 12t, 2 bytes
.j0050\@:
	jr .j0051\@ ; 12t, 2 bytes
.j0051\@:
	ENDM

sleep_46 MACRO
	jp .j0052\@ ; 10t, 3 bytes
.j0052\@:
	jr .j0053\@ ; 12t, 2 bytes
.j0053\@:
	jr .j0054\@ ; 12t, 2 bytes
.j0054\@:
	jr .j0055\@ ; 12t, 2 bytes
.j0055\@:
	ENDM

sleep_47 MACRO
	nop
	or 0
	jr .j0056\@ ; 12t, 2 bytes
.j0056\@:
	jr .j0057\@ ; 12t, 2 bytes
.j0057\@:
	jr .j0058\@ ; 12t, 2 bytes
.j0058\@:
	ENDM

sleep_48 MACRO
	jr .j0059\@ ; 12t, 2 bytes
.j0059\@:
	jr .j0060\@ ; 12t, 2 bytes
.j0060\@:
	jr .j0061\@ ; 12t, 2 bytes
.j0061\@:
	jr .j0062\@ ; 12t, 2 bytes
.j0062\@:
	ENDM

sleep_49 MACRO
	nop
	or 0
	or 0
	or 0
	jr .j0063\@ ; 12t, 2 bytes
.j0063\@:
	jr .j0064\@ ; 12t, 2 bytes
.j0064\@:
	ENDM

sleep_50 MACRO
	or 0
	or 0
	jr .j0065\@ ; 12t, 2 bytes
.j0065\@:
	jr .j0066\@ ; 12t, 2 bytes
.j0066\@:
	jr .j0067\@ ; 12t, 2 bytes
.j0067\@:
	ENDM

sleep_51 MACRO
	nop
	nop
	or 0
	jr .j0068\@ ; 12t, 2 bytes
.j0068\@:
	jr .j0069\@ ; 12t, 2 bytes
.j0069\@:
	jr .j0070\@ ; 12t, 2 bytes
.j0070\@:
	ENDM

sleep_52 MACRO
	nop
	jr .j0071\@ ; 12t, 2 bytes
.j0071\@:
	jr .j0072\@ ; 12t, 2 bytes
.j0072\@:
	jr .j0073\@ ; 12t, 2 bytes
.j0073\@:
	jr .j0074\@ ; 12t, 2 bytes
.j0074\@:
	ENDM

sleep_53 MACRO
	or 0
	jp .j0075\@ ; 10t, 3 bytes
.j0075\@:
	jr .j0076\@ ; 12t, 2 bytes
.j0076\@:
	jr .j0077\@ ; 12t, 2 bytes
.j0077\@:
	jr .j0078\@ ; 12t, 2 bytes
.j0078\@:
	ENDM

sleep_54 MACRO
	nop
	or 0
	or 0
	jr .j0079\@ ; 12t, 2 bytes
.j0079\@:
	jr .j0080\@ ; 12t, 2 bytes
.j0080\@:
	jr .j0081\@ ; 12t, 2 bytes
.j0081\@:
	ENDM

sleep_55 MACRO
	or 0
	jr .j0082\@ ; 12t, 2 bytes
.j0082\@:
	jr .j0083\@ ; 12t, 2 bytes
.j0083\@:
	jr .j0084\@ ; 12t, 2 bytes
.j0084\@:
	jr .j0085\@ ; 12t, 2 bytes
.j0085\@:
	ENDM

sleep_56 MACRO
	nop
	nop
	jr .j0086\@ ; 12t, 2 bytes
.j0086\@:
	jr .j0087\@ ; 12t, 2 bytes
.j0087\@:
	jr .j0088\@ ; 12t, 2 bytes
.j0088\@:
	jr .j0089\@ ; 12t, 2 bytes
.j0089\@:
	ENDM

sleep_57 MACRO
	or 0
	or 0
	or 0
	jr .j0090\@ ; 12t, 2 bytes
.j0090\@:
	jr .j0091\@ ; 12t, 2 bytes
.j0091\@:
	jr .j0092\@ ; 12t, 2 bytes
.j0092\@:
	ENDM

sleep_58 MACRO
	jp .j0093\@ ; 10t, 3 bytes
.j0093\@:
	jr .j0094\@ ; 12t, 2 bytes
.j0094\@:
	jr .j0095\@ ; 12t, 2 bytes
.j0095\@:
	jr .j0096\@ ; 12t, 2 bytes
.j0096\@:
	jr .j0097\@ ; 12t, 2 bytes
.j0097\@:
	ENDM

sleep_59 MACRO
	nop
	or 0
	jr .j0098\@ ; 12t, 2 bytes
.j0098\@:
	jr .j0099\@ ; 12t, 2 bytes
.j0099\@:
	jr .j0100\@ ; 12t, 2 bytes
.j0100\@:
	jr .j0101\@ ; 12t, 2 bytes
.j0101\@:
	ENDM

sleep_60 MACRO
	jr .j0102\@ ; 12t, 2 bytes
.j0102\@:
	jr .j0103\@ ; 12t, 2 bytes
.j0103\@:
	jr .j0104\@ ; 12t, 2 bytes
.j0104\@:
	jr .j0105\@ ; 12t, 2 bytes
.j0105\@:
	jr .j0106\@ ; 12t, 2 bytes
.j0106\@:
	ENDM

sleep_61 MACRO
	nop
	or 0
	or 0
	or 0
	jr .j0107\@ ; 12t, 2 bytes
.j0107\@:
	jr .j0108\@ ; 12t, 2 bytes
.j0108\@:
	jr .j0109\@ ; 12t, 2 bytes
.j0109\@:
	ENDM

sleep_62 MACRO
	or 0
	or 0
	jr .j0110\@ ; 12t, 2 bytes
.j0110\@:
	jr .j0111\@ ; 12t, 2 bytes
.j0111\@:
	jr .j0112\@ ; 12t, 2 bytes
.j0112\@:
	jr .j0113\@ ; 12t, 2 bytes
.j0113\@:
	ENDM

sleep_63 MACRO
	nop
	nop
	or 0
	jr .j0114\@ ; 12t, 2 bytes
.j0114\@:
	jr .j0115\@ ; 12t, 2 bytes
.j0115\@:
	jr .j0116\@ ; 12t, 2 bytes
.j0116\@:
	jr .j0117\@ ; 12t, 2 bytes
.j0117\@:
	ENDM

sleep_64 MACRO
	nop
	jr .j0118\@ ; 12t, 2 bytes
.j0118\@:
	jr .j0119\@ ; 12t, 2 bytes
.j0119\@:
	jr .j0120\@ ; 12t, 2 bytes
.j0120\@:
	jr .j0121\@ ; 12t, 2 bytes
.j0121\@:
	jr .j0122\@ ; 12t, 2 bytes
.j0122\@:
	ENDM

sleep_65 MACRO
	or 0
	jp .j0123\@ ; 10t, 3 bytes
.j0123\@:
	jr .j0124\@ ; 12t, 2 bytes
.j0124\@:
	jr .j0125\@ ; 12t, 2 bytes
.j0125\@:
	jr .j0126\@ ; 12t, 2 bytes
.j0126\@:
	jr .j0127\@ ; 12t, 2 bytes
.j0127\@:
	ENDM

sleep_66 MACRO
	nop
	or 0
	or 0
	jr .j0128\@ ; 12t, 2 bytes
.j0128\@:
	jr .j0129\@ ; 12t, 2 bytes
.j0129\@:
	jr .j0130\@ ; 12t, 2 bytes
.j0130\@:
	jr .j0131\@ ; 12t, 2 bytes
.j0131\@:
	ENDM

sleep_67 MACRO
	or 0
	jr .j0132\@ ; 12t, 2 bytes
.j0132\@:
	jr .j0133\@ ; 12t, 2 bytes
.j0133\@:
	jr .j0134\@ ; 12t, 2 bytes
.j0134\@:
	jr .j0135\@ ; 12t, 2 bytes
.j0135\@:
	jr .j0136\@ ; 12t, 2 bytes
.j0136\@:
	ENDM

sleep_68 MACRO
	nop
	nop
	jr .j0137\@ ; 12t, 2 bytes
.j0137\@:
	jr .j0138\@ ; 12t, 2 bytes
.j0138\@:
	jr .j0139\@ ; 12t, 2 bytes
.j0139\@:
	jr .j0140\@ ; 12t, 2 bytes
.j0140\@:
	jr .j0141\@ ; 12t, 2 bytes
.j0141\@:
	ENDM

sleep_69 MACRO
	or 0
	or 0
	or 0
	jr .j0142\@ ; 12t, 2 bytes
.j0142\@:
	jr .j0143\@ ; 12t, 2 bytes
.j0143\@:
	jr .j0144\@ ; 12t, 2 bytes
.j0144\@:
	jr .j0145\@ ; 12t, 2 bytes
.j0145\@:
	ENDM

sleep_70 MACRO
	jp .j0146\@ ; 10t, 3 bytes
.j0146\@:
	jr .j0147\@ ; 12t, 2 bytes
.j0147\@:
	jr .j0148\@ ; 12t, 2 bytes
.j0148\@:
	jr .j0149\@ ; 12t, 2 bytes
.j0149\@:
	jr .j0150\@ ; 12t, 2 bytes
.j0150\@:
	jr .j0151\@ ; 12t, 2 bytes
.j0151\@:
	ENDM

sleep_71 MACRO
	nop
	or 0
	jr .j0152\@ ; 12t, 2 bytes
.j0152\@:
	jr .j0153\@ ; 12t, 2 bytes
.j0153\@:
	jr .j0154\@ ; 12t, 2 bytes
.j0154\@:
	jr .j0155\@ ; 12t, 2 bytes
.j0155\@:
	jr .j0156\@ ; 12t, 2 bytes
.j0156\@:
	ENDM

sleep_72 MACRO
	jr .j0157\@ ; 12t, 2 bytes
.j0157\@:
	jr .j0158\@ ; 12t, 2 bytes
.j0158\@:
	jr .j0159\@ ; 12t, 2 bytes
.j0159\@:
	jr .j0160\@ ; 12t, 2 bytes
.j0160\@:
	jr .j0161\@ ; 12t, 2 bytes
.j0161\@:
	jr .j0162\@ ; 12t, 2 bytes
.j0162\@:
	ENDM

sleep_73 MACRO
	nop
	or 0
	or 0
	or 0
	jr .j0163\@ ; 12t, 2 bytes
.j0163\@:
	jr .j0164\@ ; 12t, 2 bytes
.j0164\@:
	jr .j0165\@ ; 12t, 2 bytes
.j0165\@:
	jr .j0166\@ ; 12t, 2 bytes
.j0166\@:
	ENDM

sleep_74 MACRO
	or 0
	or 0
	jr .j0167\@ ; 12t, 2 bytes
.j0167\@:
	jr .j0168\@ ; 12t, 2 bytes
.j0168\@:
	jr .j0169\@ ; 12t, 2 bytes
.j0169\@:
	jr .j0170\@ ; 12t, 2 bytes
.j0170\@:
	jr .j0171\@ ; 12t, 2 bytes
.j0171\@:
	ENDM

sleep_75 MACRO
	nop
	nop
	or 0
	jr .j0172\@ ; 12t, 2 bytes
.j0172\@:
	jr .j0173\@ ; 12t, 2 bytes
.j0173\@:
	jr .j0174\@ ; 12t, 2 bytes
.j0174\@:
	jr .j0175\@ ; 12t, 2 bytes
.j0175\@:
	jr .j0176\@ ; 12t, 2 bytes
.j0176\@:
	ENDM

sleep_76 MACRO
	nop
	jr .j0177\@ ; 12t, 2 bytes
.j0177\@:
	jr .j0178\@ ; 12t, 2 bytes
.j0178\@:
	jr .j0179\@ ; 12t, 2 bytes
.j0179\@:
	jr .j0180\@ ; 12t, 2 bytes
.j0180\@:
	jr .j0181\@ ; 12t, 2 bytes
.j0181\@:
	jr .j0182\@ ; 12t, 2 bytes
.j0182\@:
	ENDM

sleep_77 MACRO
	or 0
	jp .j0183\@ ; 10t, 3 bytes
.j0183\@:
	jr .j0184\@ ; 12t, 2 bytes
.j0184\@:
	jr .j0185\@ ; 12t, 2 bytes
.j0185\@:
	jr .j0186\@ ; 12t, 2 bytes
.j0186\@:
	jr .j0187\@ ; 12t, 2 bytes
.j0187\@:
	jr .j0188\@ ; 12t, 2 bytes
.j0188\@:
	ENDM

sleep_78 MACRO
	nop
	or 0
	or 0
	jr .j0189\@ ; 12t, 2 bytes
.j0189\@:
	jr .j0190\@ ; 12t, 2 bytes
.j0190\@:
	jr .j0191\@ ; 12t, 2 bytes
.j0191\@:
	jr .j0192\@ ; 12t, 2 bytes
.j0192\@:
	jr .j0193\@ ; 12t, 2 bytes
.j0193\@:
	ENDM

sleep_79 MACRO
	or 0
	jr .j0194\@ ; 12t, 2 bytes
.j0194\@:
	jr .j0195\@ ; 12t, 2 bytes
.j0195\@:
	jr .j0196\@ ; 12t, 2 bytes
.j0196\@:
	jr .j0197\@ ; 12t, 2 bytes
.j0197\@:
	jr .j0198\@ ; 12t, 2 bytes
.j0198\@:
	jr .j0199\@ ; 12t, 2 bytes
.j0199\@:
	ENDM

sleep_80 MACRO
	nop
	nop
	jr .j0200\@ ; 12t, 2 bytes
.j0200\@:
	jr .j0201\@ ; 12t, 2 bytes
.j0201\@:
	jr .j0202\@ ; 12t, 2 bytes
.j0202\@:
	jr .j0203\@ ; 12t, 2 bytes
.j0203\@:
	jr .j0204\@ ; 12t, 2 bytes
.j0204\@:
	jr .j0205\@ ; 12t, 2 bytes
.j0205\@:
	ENDM

sleep_81 MACRO
	or 0
	or 0
	or 0
	jr .j0206\@ ; 12t, 2 bytes
.j0206\@:
	jr .j0207\@ ; 12t, 2 bytes
.j0207\@:
	jr .j0208\@ ; 12t, 2 bytes
.j0208\@:
	jr .j0209\@ ; 12t, 2 bytes
.j0209\@:
	jr .j0210\@ ; 12t, 2 bytes
.j0210\@:
	ENDM

sleep_82 MACRO
	jp .j0211\@ ; 10t, 3 bytes
.j0211\@:
	jr .j0212\@ ; 12t, 2 bytes
.j0212\@:
	jr .j0213\@ ; 12t, 2 bytes
.j0213\@:
	jr .j0214\@ ; 12t, 2 bytes
.j0214\@:
	jr .j0215\@ ; 12t, 2 bytes
.j0215\@:
	jr .j0216\@ ; 12t, 2 bytes
.j0216\@:
	jr .j0217\@ ; 12t, 2 bytes
.j0217\@:
	ENDM

sleep_83 MACRO
	nop
	or 0
	jr .j0218\@ ; 12t, 2 bytes
.j0218\@:
	jr .j0219\@ ; 12t, 2 bytes
.j0219\@:
	jr .j0220\@ ; 12t, 2 bytes
.j0220\@:
	jr .j0221\@ ; 12t, 2 bytes
.j0221\@:
	jr .j0222\@ ; 12t, 2 bytes
.j0222\@:
	jr .j0223\@ ; 12t, 2 bytes
.j0223\@:
	ENDM

sleep_84 MACRO
	jr .j0224\@ ; 12t, 2 bytes
.j0224\@:
	jr .j0225\@ ; 12t, 2 bytes
.j0225\@:
	jr .j0226\@ ; 12t, 2 bytes
.j0226\@:
	jr .j0227\@ ; 12t, 2 bytes
.j0227\@:
	jr .j0228\@ ; 12t, 2 bytes
.j0228\@:
	jr .j0229\@ ; 12t, 2 bytes
.j0229\@:
	jr .j0230\@ ; 12t, 2 bytes
.j0230\@:
	ENDM

sleep_85 MACRO
	nop
	or 0
	or 0
	or 0
	jr .j0231\@ ; 12t, 2 bytes
.j0231\@:
	jr .j0232\@ ; 12t, 2 bytes
.j0232\@:
	jr .j0233\@ ; 12t, 2 bytes
.j0233\@:
	jr .j0234\@ ; 12t, 2 bytes
.j0234\@:
	jr .j0235\@ ; 12t, 2 bytes
.j0235\@:
	ENDM

sleep_86 MACRO
	or 0
	or 0
	jr .j0236\@ ; 12t, 2 bytes
.j0236\@:
	jr .j0237\@ ; 12t, 2 bytes
.j0237\@:
	jr .j0238\@ ; 12t, 2 bytes
.j0238\@:
	jr .j0239\@ ; 12t, 2 bytes
.j0239\@:
	jr .j0240\@ ; 12t, 2 bytes
.j0240\@:
	jr .j0241\@ ; 12t, 2 bytes
.j0241\@:
	ENDM

sleep_87 MACRO
	nop
	nop
	or 0
	jr .j0242\@ ; 12t, 2 bytes
.j0242\@:
	jr .j0243\@ ; 12t, 2 bytes
.j0243\@:
	jr .j0244\@ ; 12t, 2 bytes
.j0244\@:
	jr .j0245\@ ; 12t, 2 bytes
.j0245\@:
	jr .j0246\@ ; 12t, 2 bytes
.j0246\@:
	jr .j0247\@ ; 12t, 2 bytes
.j0247\@:
	ENDM

sleep_88 MACRO
	nop
	jr .j0248\@ ; 12t, 2 bytes
.j0248\@:
	jr .j0249\@ ; 12t, 2 bytes
.j0249\@:
	jr .j0250\@ ; 12t, 2 bytes
.j0250\@:
	jr .j0251\@ ; 12t, 2 bytes
.j0251\@:
	jr .j0252\@ ; 12t, 2 bytes
.j0252\@:
	jr .j0253\@ ; 12t, 2 bytes
.j0253\@:
	jr .j0254\@ ; 12t, 2 bytes
.j0254\@:
	ENDM

sleep_89 MACRO
	or 0
	jp .j0255\@ ; 10t, 3 bytes
.j0255\@:
	jr .j0256\@ ; 12t, 2 bytes
.j0256\@:
	jr .j0257\@ ; 12t, 2 bytes
.j0257\@:
	jr .j0258\@ ; 12t, 2 bytes
.j0258\@:
	jr .j0259\@ ; 12t, 2 bytes
.j0259\@:
	jr .j0260\@ ; 12t, 2 bytes
.j0260\@:
	jr .j0261\@ ; 12t, 2 bytes
.j0261\@:
	ENDM

sleep_90 MACRO
	nop
	or 0
	or 0
	jr .j0262\@ ; 12t, 2 bytes
.j0262\@:
	jr .j0263\@ ; 12t, 2 bytes
.j0263\@:
	jr .j0264\@ ; 12t, 2 bytes
.j0264\@:
	jr .j0265\@ ; 12t, 2 bytes
.j0265\@:
	jr .j0266\@ ; 12t, 2 bytes
.j0266\@:
	jr .j0267\@ ; 12t, 2 bytes
.j0267\@:
	ENDM

sleep_91 MACRO
	or 0
	jr .j0268\@ ; 12t, 2 bytes
.j0268\@:
	jr .j0269\@ ; 12t, 2 bytes
.j0269\@:
	jr .j0270\@ ; 12t, 2 bytes
.j0270\@:
	jr .j0271\@ ; 12t, 2 bytes
.j0271\@:
	jr .j0272\@ ; 12t, 2 bytes
.j0272\@:
	jr .j0273\@ ; 12t, 2 bytes
.j0273\@:
	jr .j0274\@ ; 12t, 2 bytes
.j0274\@:
	ENDM

sleep_92 MACRO
	nop
	nop
	jr .j0275\@ ; 12t, 2 bytes
.j0275\@:
	jr .j0276\@ ; 12t, 2 bytes
.j0276\@:
	jr .j0277\@ ; 12t, 2 bytes
.j0277\@:
	jr .j0278\@ ; 12t, 2 bytes
.j0278\@:
	jr .j0279\@ ; 12t, 2 bytes
.j0279\@:
	jr .j0280\@ ; 12t, 2 bytes
.j0280\@:
	jr .j0281\@ ; 12t, 2 bytes
.j0281\@:
	ENDM

sleep_93 MACRO
	or 0
	or 0
	or 0
	jr .j0282\@ ; 12t, 2 bytes
.j0282\@:
	jr .j0283\@ ; 12t, 2 bytes
.j0283\@:
	jr .j0284\@ ; 12t, 2 bytes
.j0284\@:
	jr .j0285\@ ; 12t, 2 bytes
.j0285\@:
	jr .j0286\@ ; 12t, 2 bytes
.j0286\@:
	jr .j0287\@ ; 12t, 2 bytes
.j0287\@:
	ENDM

sleep_94 MACRO
	jp .j0288\@ ; 10t, 3 bytes
.j0288\@:
	jr .j0289\@ ; 12t, 2 bytes
.j0289\@:
	jr .j0290\@ ; 12t, 2 bytes
.j0290\@:
	jr .j0291\@ ; 12t, 2 bytes
.j0291\@:
	jr .j0292\@ ; 12t, 2 bytes
.j0292\@:
	jr .j0293\@ ; 12t, 2 bytes
.j0293\@:
	jr .j0294\@ ; 12t, 2 bytes
.j0294\@:
	jr .j0295\@ ; 12t, 2 bytes
.j0295\@:
	ENDM

sleep_95 MACRO
	nop
	or 0
	jr .j0296\@ ; 12t, 2 bytes
.j0296\@:
	jr .j0297\@ ; 12t, 2 bytes
.j0297\@:
	jr .j0298\@ ; 12t, 2 bytes
.j0298\@:
	jr .j0299\@ ; 12t, 2 bytes
.j0299\@:
	jr .j0300\@ ; 12t, 2 bytes
.j0300\@:
	jr .j0301\@ ; 12t, 2 bytes
.j0301\@:
	jr .j0302\@ ; 12t, 2 bytes
.j0302\@:
	ENDM

sleep_96 MACRO
	jr .j0303\@ ; 12t, 2 bytes
.j0303\@:
	jr .j0304\@ ; 12t, 2 bytes
.j0304\@:
	jr .j0305\@ ; 12t, 2 bytes
.j0305\@:
	jr .j0306\@ ; 12t, 2 bytes
.j0306\@:
	jr .j0307\@ ; 12t, 2 bytes
.j0307\@:
	jr .j0308\@ ; 12t, 2 bytes
.j0308\@:
	jr .j0309\@ ; 12t, 2 bytes
.j0309\@:
	jr .j0310\@ ; 12t, 2 bytes
.j0310\@:
	ENDM

sleep_97 MACRO
	nop
	or 0
	or 0
	or 0
	jr .j0311\@ ; 12t, 2 bytes
.j0311\@:
	jr .j0312\@ ; 12t, 2 bytes
.j0312\@:
	jr .j0313\@ ; 12t, 2 bytes
.j0313\@:
	jr .j0314\@ ; 12t, 2 bytes
.j0314\@:
	jr .j0315\@ ; 12t, 2 bytes
.j0315\@:
	jr .j0316\@ ; 12t, 2 bytes
.j0316\@:
	ENDM

sleep_98 MACRO
	or 0
	or 0
	jr .j0317\@ ; 12t, 2 bytes
.j0317\@:
	jr .j0318\@ ; 12t, 2 bytes
.j0318\@:
	jr .j0319\@ ; 12t, 2 bytes
.j0319\@:
	jr .j0320\@ ; 12t, 2 bytes
.j0320\@:
	jr .j0321\@ ; 12t, 2 bytes
.j0321\@:
	jr .j0322\@ ; 12t, 2 bytes
.j0322\@:
	jr .j0323\@ ; 12t, 2 bytes
.j0323\@:
	ENDM

sleep_99 MACRO
	nop
	nop
	or 0
	jr .j0324\@ ; 12t, 2 bytes
.j0324\@:
	jr .j0325\@ ; 12t, 2 bytes
.j0325\@:
	jr .j0326\@ ; 12t, 2 bytes
.j0326\@:
	jr .j0327\@ ; 12t, 2 bytes
.j0327\@:
	jr .j0328\@ ; 12t, 2 bytes
.j0328\@:
	jr .j0329\@ ; 12t, 2 bytes
.j0329\@:
	jr .j0330\@ ; 12t, 2 bytes
.j0330\@:
	ENDM

sleep_100 MACRO
	nop
	jr .j0331\@ ; 12t, 2 bytes
.j0331\@:
	jr .j0332\@ ; 12t, 2 bytes
.j0332\@:
	jr .j0333\@ ; 12t, 2 bytes
.j0333\@:
	jr .j0334\@ ; 12t, 2 bytes
.j0334\@:
	jr .j0335\@ ; 12t, 2 bytes
.j0335\@:
	jr .j0336\@ ; 12t, 2 bytes
.j0336\@:
	jr .j0337\@ ; 12t, 2 bytes
.j0337\@:
	jr .j0338\@ ; 12t, 2 bytes
.j0338\@:
	ENDM

sleep_101 MACRO
	or 0
	jp .j0339\@ ; 10t, 3 bytes
.j0339\@:
	jr .j0340\@ ; 12t, 2 bytes
.j0340\@:
	jr .j0341\@ ; 12t, 2 bytes
.j0341\@:
	jr .j0342\@ ; 12t, 2 bytes
.j0342\@:
	jr .j0343\@ ; 12t, 2 bytes
.j0343\@:
	jr .j0344\@ ; 12t, 2 bytes
.j0344\@:
	jr .j0345\@ ; 12t, 2 bytes
.j0345\@:
	jr .j0346\@ ; 12t, 2 bytes
.j0346\@:
	ENDM

sleep_102 MACRO
	nop
	or 0
	or 0
	jr .j0347\@ ; 12t, 2 bytes
.j0347\@:
	jr .j0348\@ ; 12t, 2 bytes
.j0348\@:
	jr .j0349\@ ; 12t, 2 bytes
.j0349\@:
	jr .j0350\@ ; 12t, 2 bytes
.j0350\@:
	jr .j0351\@ ; 12t, 2 bytes
.j0351\@:
	jr .j0352\@ ; 12t, 2 bytes
.j0352\@:
	jr .j0353\@ ; 12t, 2 bytes
.j0353\@:
	ENDM

sleep_103 MACRO
	or 0
	jr .j0354\@ ; 12t, 2 bytes
.j0354\@:
	jr .j0355\@ ; 12t, 2 bytes
.j0355\@:
	jr .j0356\@ ; 12t, 2 bytes
.j0356\@:
	jr .j0357\@ ; 12t, 2 bytes
.j0357\@:
	jr .j0358\@ ; 12t, 2 bytes
.j0358\@:
	jr .j0359\@ ; 12t, 2 bytes
.j0359\@:
	jr .j0360\@ ; 12t, 2 bytes
.j0360\@:
	jr .j0361\@ ; 12t, 2 bytes
.j0361\@:
	ENDM

sleep_104 MACRO
	nop
	nop
	jr .j0362\@ ; 12t, 2 bytes
.j0362\@:
	jr .j0363\@ ; 12t, 2 bytes
.j0363\@:
	jr .j0364\@ ; 12t, 2 bytes
.j0364\@:
	jr .j0365\@ ; 12t, 2 bytes
.j0365\@:
	jr .j0366\@ ; 12t, 2 bytes
.j0366\@:
	jr .j0367\@ ; 12t, 2 bytes
.j0367\@:
	jr .j0368\@ ; 12t, 2 bytes
.j0368\@:
	jr .j0369\@ ; 12t, 2 bytes
.j0369\@:
	ENDM

sleep_105 MACRO
	or 0
	or 0
	or 0
	jr .j0370\@ ; 12t, 2 bytes
.j0370\@:
	jr .j0371\@ ; 12t, 2 bytes
.j0371\@:
	jr .j0372\@ ; 12t, 2 bytes
.j0372\@:
	jr .j0373\@ ; 12t, 2 bytes
.j0373\@:
	jr .j0374\@ ; 12t, 2 bytes
.j0374\@:
	jr .j0375\@ ; 12t, 2 bytes
.j0375\@:
	jr .j0376\@ ; 12t, 2 bytes
.j0376\@:
	ENDM

sleep_106 MACRO
	jp .j0377\@ ; 10t, 3 bytes
.j0377\@:
	jr .j0378\@ ; 12t, 2 bytes
.j0378\@:
	jr .j0379\@ ; 12t, 2 bytes
.j0379\@:
	jr .j0380\@ ; 12t, 2 bytes
.j0380\@:
	jr .j0381\@ ; 12t, 2 bytes
.j0381\@:
	jr .j0382\@ ; 12t, 2 bytes
.j0382\@:
	jr .j0383\@ ; 12t, 2 bytes
.j0383\@:
	jr .j0384\@ ; 12t, 2 bytes
.j0384\@:
	jr .j0385\@ ; 12t, 2 bytes
.j0385\@:
	ENDM

sleep_107 MACRO
	nop
	or 0
	jr .j0386\@ ; 12t, 2 bytes
.j0386\@:
	jr .j0387\@ ; 12t, 2 bytes
.j0387\@:
	jr .j0388\@ ; 12t, 2 bytes
.j0388\@:
	jr .j0389\@ ; 12t, 2 bytes
.j0389\@:
	jr .j0390\@ ; 12t, 2 bytes
.j0390\@:
	jr .j0391\@ ; 12t, 2 bytes
.j0391\@:
	jr .j0392\@ ; 12t, 2 bytes
.j0392\@:
	jr .j0393\@ ; 12t, 2 bytes
.j0393\@:
	ENDM

sleep_108 MACRO
	jr .j0394\@ ; 12t, 2 bytes
.j0394\@:
	jr .j0395\@ ; 12t, 2 bytes
.j0395\@:
	jr .j0396\@ ; 12t, 2 bytes
.j0396\@:
	jr .j0397\@ ; 12t, 2 bytes
.j0397\@:
	jr .j0398\@ ; 12t, 2 bytes
.j0398\@:
	jr .j0399\@ ; 12t, 2 bytes
.j0399\@:
	jr .j0400\@ ; 12t, 2 bytes
.j0400\@:
	jr .j0401\@ ; 12t, 2 bytes
.j0401\@:
	jr .j0402\@ ; 12t, 2 bytes
.j0402\@:
	ENDM

sleep_109 MACRO
	nop
	or 0
	or 0
	or 0
	jr .j0403\@ ; 12t, 2 bytes
.j0403\@:
	jr .j0404\@ ; 12t, 2 bytes
.j0404\@:
	jr .j0405\@ ; 12t, 2 bytes
.j0405\@:
	jr .j0406\@ ; 12t, 2 bytes
.j0406\@:
	jr .j0407\@ ; 12t, 2 bytes
.j0407\@:
	jr .j0408\@ ; 12t, 2 bytes
.j0408\@:
	jr .j0409\@ ; 12t, 2 bytes
.j0409\@:
	ENDM

sleep_110 MACRO
	or 0
	or 0
	jr .j0410\@ ; 12t, 2 bytes
.j0410\@:
	jr .j0411\@ ; 12t, 2 bytes
.j0411\@:
	jr .j0412\@ ; 12t, 2 bytes
.j0412\@:
	jr .j0413\@ ; 12t, 2 bytes
.j0413\@:
	jr .j0414\@ ; 12t, 2 bytes
.j0414\@:
	jr .j0415\@ ; 12t, 2 bytes
.j0415\@:
	jr .j0416\@ ; 12t, 2 bytes
.j0416\@:
	jr .j0417\@ ; 12t, 2 bytes
.j0417\@:
	ENDM

sleep_111 MACRO
	nop
	nop
	or 0
	jr .j0418\@ ; 12t, 2 bytes
.j0418\@:
	jr .j0419\@ ; 12t, 2 bytes
.j0419\@:
	jr .j0420\@ ; 12t, 2 bytes
.j0420\@:
	jr .j0421\@ ; 12t, 2 bytes
.j0421\@:
	jr .j0422\@ ; 12t, 2 bytes
.j0422\@:
	jr .j0423\@ ; 12t, 2 bytes
.j0423\@:
	jr .j0424\@ ; 12t, 2 bytes
.j0424\@:
	jr .j0425\@ ; 12t, 2 bytes
.j0425\@:
	ENDM

sleep_112 MACRO
	nop
	jr .j0426\@ ; 12t, 2 bytes
.j0426\@:
	jr .j0427\@ ; 12t, 2 bytes
.j0427\@:
	jr .j0428\@ ; 12t, 2 bytes
.j0428\@:
	jr .j0429\@ ; 12t, 2 bytes
.j0429\@:
	jr .j0430\@ ; 12t, 2 bytes
.j0430\@:
	jr .j0431\@ ; 12t, 2 bytes
.j0431\@:
	jr .j0432\@ ; 12t, 2 bytes
.j0432\@:
	jr .j0433\@ ; 12t, 2 bytes
.j0433\@:
	jr .j0434\@ ; 12t, 2 bytes
.j0434\@:
	ENDM

sleep_113 MACRO
	or 0
	jp .j0435\@ ; 10t, 3 bytes
.j0435\@:
	jr .j0436\@ ; 12t, 2 bytes
.j0436\@:
	jr .j0437\@ ; 12t, 2 bytes
.j0437\@:
	jr .j0438\@ ; 12t, 2 bytes
.j0438\@:
	jr .j0439\@ ; 12t, 2 bytes
.j0439\@:
	jr .j0440\@ ; 12t, 2 bytes
.j0440\@:
	jr .j0441\@ ; 12t, 2 bytes
.j0441\@:
	jr .j0442\@ ; 12t, 2 bytes
.j0442\@:
	jr .j0443\@ ; 12t, 2 bytes
.j0443\@:
	ENDM

sleep_114 MACRO
	nop
	or 0
	or 0
	jr .j0444\@ ; 12t, 2 bytes
.j0444\@:
	jr .j0445\@ ; 12t, 2 bytes
.j0445\@:
	jr .j0446\@ ; 12t, 2 bytes
.j0446\@:
	jr .j0447\@ ; 12t, 2 bytes
.j0447\@:
	jr .j0448\@ ; 12t, 2 bytes
.j0448\@:
	jr .j0449\@ ; 12t, 2 bytes
.j0449\@:
	jr .j0450\@ ; 12t, 2 bytes
.j0450\@:
	jr .j0451\@ ; 12t, 2 bytes
.j0451\@:
	ENDM

sleep_115 MACRO
	or 0
	jr .j0452\@ ; 12t, 2 bytes
.j0452\@:
	jr .j0453\@ ; 12t, 2 bytes
.j0453\@:
	jr .j0454\@ ; 12t, 2 bytes
.j0454\@:
	jr .j0455\@ ; 12t, 2 bytes
.j0455\@:
	jr .j0456\@ ; 12t, 2 bytes
.j0456\@:
	jr .j0457\@ ; 12t, 2 bytes
.j0457\@:
	jr .j0458\@ ; 12t, 2 bytes
.j0458\@:
	jr .j0459\@ ; 12t, 2 bytes
.j0459\@:
	jr .j0460\@ ; 12t, 2 bytes
.j0460\@:
	ENDM

sleep_116 MACRO
	nop
	nop
	jr .j0461\@ ; 12t, 2 bytes
.j0461\@:
	jr .j0462\@ ; 12t, 2 bytes
.j0462\@:
	jr .j0463\@ ; 12t, 2 bytes
.j0463\@:
	jr .j0464\@ ; 12t, 2 bytes
.j0464\@:
	jr .j0465\@ ; 12t, 2 bytes
.j0465\@:
	jr .j0466\@ ; 12t, 2 bytes
.j0466\@:
	jr .j0467\@ ; 12t, 2 bytes
.j0467\@:
	jr .j0468\@ ; 12t, 2 bytes
.j0468\@:
	jr .j0469\@ ; 12t, 2 bytes
.j0469\@:
	ENDM

sleep_117 MACRO
	or 0
	or 0
	or 0
	jr .j0470\@ ; 12t, 2 bytes
.j0470\@:
	jr .j0471\@ ; 12t, 2 bytes
.j0471\@:
	jr .j0472\@ ; 12t, 2 bytes
.j0472\@:
	jr .j0473\@ ; 12t, 2 bytes
.j0473\@:
	jr .j0474\@ ; 12t, 2 bytes
.j0474\@:
	jr .j0475\@ ; 12t, 2 bytes
.j0475\@:
	jr .j0476\@ ; 12t, 2 bytes
.j0476\@:
	jr .j0477\@ ; 12t, 2 bytes
.j0477\@:
	ENDM

sleep_118 MACRO
	jp .j0478\@ ; 10t, 3 bytes
.j0478\@:
	jr .j0479\@ ; 12t, 2 bytes
.j0479\@:
	jr .j0480\@ ; 12t, 2 bytes
.j0480\@:
	jr .j0481\@ ; 12t, 2 bytes
.j0481\@:
	jr .j0482\@ ; 12t, 2 bytes
.j0482\@:
	jr .j0483\@ ; 12t, 2 bytes
.j0483\@:
	jr .j0484\@ ; 12t, 2 bytes
.j0484\@:
	jr .j0485\@ ; 12t, 2 bytes
.j0485\@:
	jr .j0486\@ ; 12t, 2 bytes
.j0486\@:
	jr .j0487\@ ; 12t, 2 bytes
.j0487\@:
	ENDM

sleep_119 MACRO
	nop
	or 0
	jr .j0488\@ ; 12t, 2 bytes
.j0488\@:
	jr .j0489\@ ; 12t, 2 bytes
.j0489\@:
	jr .j0490\@ ; 12t, 2 bytes
.j0490\@:
	jr .j0491\@ ; 12t, 2 bytes
.j0491\@:
	jr .j0492\@ ; 12t, 2 bytes
.j0492\@:
	jr .j0493\@ ; 12t, 2 bytes
.j0493\@:
	jr .j0494\@ ; 12t, 2 bytes
.j0494\@:
	jr .j0495\@ ; 12t, 2 bytes
.j0495\@:
	jr .j0496\@ ; 12t, 2 bytes
.j0496\@:
	ENDM

sleep_120 MACRO
	jr .j0497\@ ; 12t, 2 bytes
.j0497\@:
	jr .j0498\@ ; 12t, 2 bytes
.j0498\@:
	jr .j0499\@ ; 12t, 2 bytes
.j0499\@:
	jr .j0500\@ ; 12t, 2 bytes
.j0500\@:
	jr .j0501\@ ; 12t, 2 bytes
.j0501\@:
	jr .j0502\@ ; 12t, 2 bytes
.j0502\@:
	jr .j0503\@ ; 12t, 2 bytes
.j0503\@:
	jr .j0504\@ ; 12t, 2 bytes
.j0504\@:
	jr .j0505\@ ; 12t, 2 bytes
.j0505\@:
	jr .j0506\@ ; 12t, 2 bytes
.j0506\@:
	ENDM

sleep_121 MACRO
	nop
	or 0
	or 0
	or 0
	jr .j0507\@ ; 12t, 2 bytes
.j0507\@:
	jr .j0508\@ ; 12t, 2 bytes
.j0508\@:
	jr .j0509\@ ; 12t, 2 bytes
.j0509\@:
	jr .j0510\@ ; 12t, 2 bytes
.j0510\@:
	jr .j0511\@ ; 12t, 2 bytes
.j0511\@:
	jr .j0512\@ ; 12t, 2 bytes
.j0512\@:
	jr .j0513\@ ; 12t, 2 bytes
.j0513\@:
	jr .j0514\@ ; 12t, 2 bytes
.j0514\@:
	ENDM

sleep_122 MACRO
	or 0
	or 0
	jr .j0515\@ ; 12t, 2 bytes
.j0515\@:
	jr .j0516\@ ; 12t, 2 bytes
.j0516\@:
	jr .j0517\@ ; 12t, 2 bytes
.j0517\@:
	jr .j0518\@ ; 12t, 2 bytes
.j0518\@:
	jr .j0519\@ ; 12t, 2 bytes
.j0519\@:
	jr .j0520\@ ; 12t, 2 bytes
.j0520\@:
	jr .j0521\@ ; 12t, 2 bytes
.j0521\@:
	jr .j0522\@ ; 12t, 2 bytes
.j0522\@:
	jr .j0523\@ ; 12t, 2 bytes
.j0523\@:
	ENDM

sleep_123 MACRO
	nop
	nop
	or 0
	jr .j0524\@ ; 12t, 2 bytes
.j0524\@:
	jr .j0525\@ ; 12t, 2 bytes
.j0525\@:
	jr .j0526\@ ; 12t, 2 bytes
.j0526\@:
	jr .j0527\@ ; 12t, 2 bytes
.j0527\@:
	jr .j0528\@ ; 12t, 2 bytes
.j0528\@:
	jr .j0529\@ ; 12t, 2 bytes
.j0529\@:
	jr .j0530\@ ; 12t, 2 bytes
.j0530\@:
	jr .j0531\@ ; 12t, 2 bytes
.j0531\@:
	jr .j0532\@ ; 12t, 2 bytes
.j0532\@:
	ENDM

sleep_124 MACRO
	nop
	jr .j0533\@ ; 12t, 2 bytes
.j0533\@:
	jr .j0534\@ ; 12t, 2 bytes
.j0534\@:
	jr .j0535\@ ; 12t, 2 bytes
.j0535\@:
	jr .j0536\@ ; 12t, 2 bytes
.j0536\@:
	jr .j0537\@ ; 12t, 2 bytes
.j0537\@:
	jr .j0538\@ ; 12t, 2 bytes
.j0538\@:
	jr .j0539\@ ; 12t, 2 bytes
.j0539\@:
	jr .j0540\@ ; 12t, 2 bytes
.j0540\@:
	jr .j0541\@ ; 12t, 2 bytes
.j0541\@:
	jr .j0542\@ ; 12t, 2 bytes
.j0542\@:
	ENDM

sleep_125 MACRO
	or 0
	jp .j0543\@ ; 10t, 3 bytes
.j0543\@:
	jr .j0544\@ ; 12t, 2 bytes
.j0544\@:
	jr .j0545\@ ; 12t, 2 bytes
.j0545\@:
	jr .j0546\@ ; 12t, 2 bytes
.j0546\@:
	jr .j0547\@ ; 12t, 2 bytes
.j0547\@:
	jr .j0548\@ ; 12t, 2 bytes
.j0548\@:
	jr .j0549\@ ; 12t, 2 bytes
.j0549\@:
	jr .j0550\@ ; 12t, 2 bytes
.j0550\@:
	jr .j0551\@ ; 12t, 2 bytes
.j0551\@:
	jr .j0552\@ ; 12t, 2 bytes
.j0552\@:
	ENDM

sleep_126 MACRO
	nop
	or 0
	or 0
	jr .j0553\@ ; 12t, 2 bytes
.j0553\@:
	jr .j0554\@ ; 12t, 2 bytes
.j0554\@:
	jr .j0555\@ ; 12t, 2 bytes
.j0555\@:
	jr .j0556\@ ; 12t, 2 bytes
.j0556\@:
	jr .j0557\@ ; 12t, 2 bytes
.j0557\@:
	jr .j0558\@ ; 12t, 2 bytes
.j0558\@:
	jr .j0559\@ ; 12t, 2 bytes
.j0559\@:
	jr .j0560\@ ; 12t, 2 bytes
.j0560\@:
	jr .j0561\@ ; 12t, 2 bytes
.j0561\@:
	ENDM

sleep_127 MACRO
	or 0
	jr .j0562\@ ; 12t, 2 bytes
.j0562\@:
	jr .j0563\@ ; 12t, 2 bytes
.j0563\@:
	jr .j0564\@ ; 12t, 2 bytes
.j0564\@:
	jr .j0565\@ ; 12t, 2 bytes
.j0565\@:
	jr .j0566\@ ; 12t, 2 bytes
.j0566\@:
	jr .j0567\@ ; 12t, 2 bytes
.j0567\@:
	jr .j0568\@ ; 12t, 2 bytes
.j0568\@:
	jr .j0569\@ ; 12t, 2 bytes
.j0569\@:
	jr .j0570\@ ; 12t, 2 bytes
.j0570\@:
	jr .j0571\@ ; 12t, 2 bytes
.j0571\@:
	ENDM

sleep_128 MACRO
	nop
	nop
	jr .j0572\@ ; 12t, 2 bytes
.j0572\@:
	jr .j0573\@ ; 12t, 2 bytes
.j0573\@:
	jr .j0574\@ ; 12t, 2 bytes
.j0574\@:
	jr .j0575\@ ; 12t, 2 bytes
.j0575\@:
	jr .j0576\@ ; 12t, 2 bytes
.j0576\@:
	jr .j0577\@ ; 12t, 2 bytes
.j0577\@:
	jr .j0578\@ ; 12t, 2 bytes
.j0578\@:
	jr .j0579\@ ; 12t, 2 bytes
.j0579\@:
	jr .j0580\@ ; 12t, 2 bytes
.j0580\@:
	jr .j0581\@ ; 12t, 2 bytes
.j0581\@:
	ENDM

sleep_129 MACRO
	or 0
	or 0
	or 0
	jr .j0582\@ ; 12t, 2 bytes
.j0582\@:
	jr .j0583\@ ; 12t, 2 bytes
.j0583\@:
	jr .j0584\@ ; 12t, 2 bytes
.j0584\@:
	jr .j0585\@ ; 12t, 2 bytes
.j0585\@:
	jr .j0586\@ ; 12t, 2 bytes
.j0586\@:
	jr .j0587\@ ; 12t, 2 bytes
.j0587\@:
	jr .j0588\@ ; 12t, 2 bytes
.j0588\@:
	jr .j0589\@ ; 12t, 2 bytes
.j0589\@:
	jr .j0590\@ ; 12t, 2 bytes
.j0590\@:
	ENDM

sleep_130 MACRO
	jp .j0591\@ ; 10t, 3 bytes
.j0591\@:
	jr .j0592\@ ; 12t, 2 bytes
.j0592\@:
	jr .j0593\@ ; 12t, 2 bytes
.j0593\@:
	jr .j0594\@ ; 12t, 2 bytes
.j0594\@:
	jr .j0595\@ ; 12t, 2 bytes
.j0595\@:
	jr .j0596\@ ; 12t, 2 bytes
.j0596\@:
	jr .j0597\@ ; 12t, 2 bytes
.j0597\@:
	jr .j0598\@ ; 12t, 2 bytes
.j0598\@:
	jr .j0599\@ ; 12t, 2 bytes
.j0599\@:
	jr .j0600\@ ; 12t, 2 bytes
.j0600\@:
	jr .j0601\@ ; 12t, 2 bytes
.j0601\@:
	ENDM

sleep_131 MACRO
	nop
	or 0
	jr .j0602\@ ; 12t, 2 bytes
.j0602\@:
	jr .j0603\@ ; 12t, 2 bytes
.j0603\@:
	jr .j0604\@ ; 12t, 2 bytes
.j0604\@:
	jr .j0605\@ ; 12t, 2 bytes
.j0605\@:
	jr .j0606\@ ; 12t, 2 bytes
.j0606\@:
	jr .j0607\@ ; 12t, 2 bytes
.j0607\@:
	jr .j0608\@ ; 12t, 2 bytes
.j0608\@:
	jr .j0609\@ ; 12t, 2 bytes
.j0609\@:
	jr .j0610\@ ; 12t, 2 bytes
.j0610\@:
	jr .j0611\@ ; 12t, 2 bytes
.j0611\@:
	ENDM

sleep_132 MACRO
	jr .j0612\@ ; 12t, 2 bytes
.j0612\@:
	jr .j0613\@ ; 12t, 2 bytes
.j0613\@:
	jr .j0614\@ ; 12t, 2 bytes
.j0614\@:
	jr .j0615\@ ; 12t, 2 bytes
.j0615\@:
	jr .j0616\@ ; 12t, 2 bytes
.j0616\@:
	jr .j0617\@ ; 12t, 2 bytes
.j0617\@:
	jr .j0618\@ ; 12t, 2 bytes
.j0618\@:
	jr .j0619\@ ; 12t, 2 bytes
.j0619\@:
	jr .j0620\@ ; 12t, 2 bytes
.j0620\@:
	jr .j0621\@ ; 12t, 2 bytes
.j0621\@:
	jr .j0622\@ ; 12t, 2 bytes
.j0622\@:
	ENDM

sleep_133 MACRO
	nop
	or 0
	or 0
	or 0
	jr .j0623\@ ; 12t, 2 bytes
.j0623\@:
	jr .j0624\@ ; 12t, 2 bytes
.j0624\@:
	jr .j0625\@ ; 12t, 2 bytes
.j0625\@:
	jr .j0626\@ ; 12t, 2 bytes
.j0626\@:
	jr .j0627\@ ; 12t, 2 bytes
.j0627\@:
	jr .j0628\@ ; 12t, 2 bytes
.j0628\@:
	jr .j0629\@ ; 12t, 2 bytes
.j0629\@:
	jr .j0630\@ ; 12t, 2 bytes
.j0630\@:
	jr .j0631\@ ; 12t, 2 bytes
.j0631\@:
	ENDM

sleep_134 MACRO
	or 0
	or 0
	jr .j0632\@ ; 12t, 2 bytes
.j0632\@:
	jr .j0633\@ ; 12t, 2 bytes
.j0633\@:
	jr .j0634\@ ; 12t, 2 bytes
.j0634\@:
	jr .j0635\@ ; 12t, 2 bytes
.j0635\@:
	jr .j0636\@ ; 12t, 2 bytes
.j0636\@:
	jr .j0637\@ ; 12t, 2 bytes
.j0637\@:
	jr .j0638\@ ; 12t, 2 bytes
.j0638\@:
	jr .j0639\@ ; 12t, 2 bytes
.j0639\@:
	jr .j0640\@ ; 12t, 2 bytes
.j0640\@:
	jr .j0641\@ ; 12t, 2 bytes
.j0641\@:
	ENDM

sleep_135 MACRO
	nop
	nop
	or 0
	jr .j0642\@ ; 12t, 2 bytes
.j0642\@:
	jr .j0643\@ ; 12t, 2 bytes
.j0643\@:
	jr .j0644\@ ; 12t, 2 bytes
.j0644\@:
	jr .j0645\@ ; 12t, 2 bytes
.j0645\@:
	jr .j0646\@ ; 12t, 2 bytes
.j0646\@:
	jr .j0647\@ ; 12t, 2 bytes
.j0647\@:
	jr .j0648\@ ; 12t, 2 bytes
.j0648\@:
	jr .j0649\@ ; 12t, 2 bytes
.j0649\@:
	jr .j0650\@ ; 12t, 2 bytes
.j0650\@:
	jr .j0651\@ ; 12t, 2 bytes
.j0651\@:
	ENDM

sleep_136 MACRO
	nop
	jr .j0652\@ ; 12t, 2 bytes
.j0652\@:
	jr .j0653\@ ; 12t, 2 bytes
.j0653\@:
	jr .j0654\@ ; 12t, 2 bytes
.j0654\@:
	jr .j0655\@ ; 12t, 2 bytes
.j0655\@:
	jr .j0656\@ ; 12t, 2 bytes
.j0656\@:
	jr .j0657\@ ; 12t, 2 bytes
.j0657\@:
	jr .j0658\@ ; 12t, 2 bytes
.j0658\@:
	jr .j0659\@ ; 12t, 2 bytes
.j0659\@:
	jr .j0660\@ ; 12t, 2 bytes
.j0660\@:
	jr .j0661\@ ; 12t, 2 bytes
.j0661\@:
	jr .j0662\@ ; 12t, 2 bytes
.j0662\@:
	ENDM

sleep_137 MACRO
	or 0
	jp .j0663\@ ; 10t, 3 bytes
.j0663\@:
	jr .j0664\@ ; 12t, 2 bytes
.j0664\@:
	jr .j0665\@ ; 12t, 2 bytes
.j0665\@:
	jr .j0666\@ ; 12t, 2 bytes
.j0666\@:
	jr .j0667\@ ; 12t, 2 bytes
.j0667\@:
	jr .j0668\@ ; 12t, 2 bytes
.j0668\@:
	jr .j0669\@ ; 12t, 2 bytes
.j0669\@:
	jr .j0670\@ ; 12t, 2 bytes
.j0670\@:
	jr .j0671\@ ; 12t, 2 bytes
.j0671\@:
	jr .j0672\@ ; 12t, 2 bytes
.j0672\@:
	jr .j0673\@ ; 12t, 2 bytes
.j0673\@:
	ENDM

sleep_138 MACRO
	nop
	or 0
	or 0
	jr .j0674\@ ; 12t, 2 bytes
.j0674\@:
	jr .j0675\@ ; 12t, 2 bytes
.j0675\@:
	jr .j0676\@ ; 12t, 2 bytes
.j0676\@:
	jr .j0677\@ ; 12t, 2 bytes
.j0677\@:
	jr .j0678\@ ; 12t, 2 bytes
.j0678\@:
	jr .j0679\@ ; 12t, 2 bytes
.j0679\@:
	jr .j0680\@ ; 12t, 2 bytes
.j0680\@:
	jr .j0681\@ ; 12t, 2 bytes
.j0681\@:
	jr .j0682\@ ; 12t, 2 bytes
.j0682\@:
	jr .j0683\@ ; 12t, 2 bytes
.j0683\@:
	ENDM

sleep_139 MACRO
	or 0
	jr .j0684\@ ; 12t, 2 bytes
.j0684\@:
	jr .j0685\@ ; 12t, 2 bytes
.j0685\@:
	jr .j0686\@ ; 12t, 2 bytes
.j0686\@:
	jr .j0687\@ ; 12t, 2 bytes
.j0687\@:
	jr .j0688\@ ; 12t, 2 bytes
.j0688\@:
	jr .j0689\@ ; 12t, 2 bytes
.j0689\@:
	jr .j0690\@ ; 12t, 2 bytes
.j0690\@:
	jr .j0691\@ ; 12t, 2 bytes
.j0691\@:
	jr .j0692\@ ; 12t, 2 bytes
.j0692\@:
	jr .j0693\@ ; 12t, 2 bytes
.j0693\@:
	jr .j0694\@ ; 12t, 2 bytes
.j0694\@:
	ENDM

sleep_140 MACRO
	nop
	nop
	jr .j0695\@ ; 12t, 2 bytes
.j0695\@:
	jr .j0696\@ ; 12t, 2 bytes
.j0696\@:
	jr .j0697\@ ; 12t, 2 bytes
.j0697\@:
	jr .j0698\@ ; 12t, 2 bytes
.j0698\@:
	jr .j0699\@ ; 12t, 2 bytes
.j0699\@:
	jr .j0700\@ ; 12t, 2 bytes
.j0700\@:
	jr .j0701\@ ; 12t, 2 bytes
.j0701\@:
	jr .j0702\@ ; 12t, 2 bytes
.j0702\@:
	jr .j0703\@ ; 12t, 2 bytes
.j0703\@:
	jr .j0704\@ ; 12t, 2 bytes
.j0704\@:
	jr .j0705\@ ; 12t, 2 bytes
.j0705\@:
	ENDM

sleep_141 MACRO
	or 0
	or 0
	or 0
	jr .j0706\@ ; 12t, 2 bytes
.j0706\@:
	jr .j0707\@ ; 12t, 2 bytes
.j0707\@:
	jr .j0708\@ ; 12t, 2 bytes
.j0708\@:
	jr .j0709\@ ; 12t, 2 bytes
.j0709\@:
	jr .j0710\@ ; 12t, 2 bytes
.j0710\@:
	jr .j0711\@ ; 12t, 2 bytes
.j0711\@:
	jr .j0712\@ ; 12t, 2 bytes
.j0712\@:
	jr .j0713\@ ; 12t, 2 bytes
.j0713\@:
	jr .j0714\@ ; 12t, 2 bytes
.j0714\@:
	jr .j0715\@ ; 12t, 2 bytes
.j0715\@:
	ENDM

sleep_142 MACRO
	jp .j0716\@ ; 10t, 3 bytes
.j0716\@:
	jr .j0717\@ ; 12t, 2 bytes
.j0717\@:
	jr .j0718\@ ; 12t, 2 bytes
.j0718\@:
	jr .j0719\@ ; 12t, 2 bytes
.j0719\@:
	jr .j0720\@ ; 12t, 2 bytes
.j0720\@:
	jr .j0721\@ ; 12t, 2 bytes
.j0721\@:
	jr .j0722\@ ; 12t, 2 bytes
.j0722\@:
	jr .j0723\@ ; 12t, 2 bytes
.j0723\@:
	jr .j0724\@ ; 12t, 2 bytes
.j0724\@:
	jr .j0725\@ ; 12t, 2 bytes
.j0725\@:
	jr .j0726\@ ; 12t, 2 bytes
.j0726\@:
	jr .j0727\@ ; 12t, 2 bytes
.j0727\@:
	ENDM

sleep_143 MACRO
	nop
	or 0
	jr .j0728\@ ; 12t, 2 bytes
.j0728\@:
	jr .j0729\@ ; 12t, 2 bytes
.j0729\@:
	jr .j0730\@ ; 12t, 2 bytes
.j0730\@:
	jr .j0731\@ ; 12t, 2 bytes
.j0731\@:
	jr .j0732\@ ; 12t, 2 bytes
.j0732\@:
	jr .j0733\@ ; 12t, 2 bytes
.j0733\@:
	jr .j0734\@ ; 12t, 2 bytes
.j0734\@:
	jr .j0735\@ ; 12t, 2 bytes
.j0735\@:
	jr .j0736\@ ; 12t, 2 bytes
.j0736\@:
	jr .j0737\@ ; 12t, 2 bytes
.j0737\@:
	jr .j0738\@ ; 12t, 2 bytes
.j0738\@:
	ENDM

sleep_144 MACRO
	jr .j0739\@ ; 12t, 2 bytes
.j0739\@:
	jr .j0740\@ ; 12t, 2 bytes
.j0740\@:
	jr .j0741\@ ; 12t, 2 bytes
.j0741\@:
	jr .j0742\@ ; 12t, 2 bytes
.j0742\@:
	jr .j0743\@ ; 12t, 2 bytes
.j0743\@:
	jr .j0744\@ ; 12t, 2 bytes
.j0744\@:
	jr .j0745\@ ; 12t, 2 bytes
.j0745\@:
	jr .j0746\@ ; 12t, 2 bytes
.j0746\@:
	jr .j0747\@ ; 12t, 2 bytes
.j0747\@:
	jr .j0748\@ ; 12t, 2 bytes
.j0748\@:
	jr .j0749\@ ; 12t, 2 bytes
.j0749\@:
	jr .j0750\@ ; 12t, 2 bytes
.j0750\@:
	ENDM

sleep_145 MACRO
	nop
	or 0
	or 0
	or 0
	jr .j0751\@ ; 12t, 2 bytes
.j0751\@:
	jr .j0752\@ ; 12t, 2 bytes
.j0752\@:
	jr .j0753\@ ; 12t, 2 bytes
.j0753\@:
	jr .j0754\@ ; 12t, 2 bytes
.j0754\@:
	jr .j0755\@ ; 12t, 2 bytes
.j0755\@:
	jr .j0756\@ ; 12t, 2 bytes
.j0756\@:
	jr .j0757\@ ; 12t, 2 bytes
.j0757\@:
	jr .j0758\@ ; 12t, 2 bytes
.j0758\@:
	jr .j0759\@ ; 12t, 2 bytes
.j0759\@:
	jr .j0760\@ ; 12t, 2 bytes
.j0760\@:
	ENDM

sleep_146 MACRO
	or 0
	or 0
	jr .j0761\@ ; 12t, 2 bytes
.j0761\@:
	jr .j0762\@ ; 12t, 2 bytes
.j0762\@:
	jr .j0763\@ ; 12t, 2 bytes
.j0763\@:
	jr .j0764\@ ; 12t, 2 bytes
.j0764\@:
	jr .j0765\@ ; 12t, 2 bytes
.j0765\@:
	jr .j0766\@ ; 12t, 2 bytes
.j0766\@:
	jr .j0767\@ ; 12t, 2 bytes
.j0767\@:
	jr .j0768\@ ; 12t, 2 bytes
.j0768\@:
	jr .j0769\@ ; 12t, 2 bytes
.j0769\@:
	jr .j0770\@ ; 12t, 2 bytes
.j0770\@:
	jr .j0771\@ ; 12t, 2 bytes
.j0771\@:
	ENDM

sleep_147 MACRO
	nop
	nop
	or 0
	jr .j0772\@ ; 12t, 2 bytes
.j0772\@:
	jr .j0773\@ ; 12t, 2 bytes
.j0773\@:
	jr .j0774\@ ; 12t, 2 bytes
.j0774\@:
	jr .j0775\@ ; 12t, 2 bytes
.j0775\@:
	jr .j0776\@ ; 12t, 2 bytes
.j0776\@:
	jr .j0777\@ ; 12t, 2 bytes
.j0777\@:
	jr .j0778\@ ; 12t, 2 bytes
.j0778\@:
	jr .j0779\@ ; 12t, 2 bytes
.j0779\@:
	jr .j0780\@ ; 12t, 2 bytes
.j0780\@:
	jr .j0781\@ ; 12t, 2 bytes
.j0781\@:
	jr .j0782\@ ; 12t, 2 bytes
.j0782\@:
	ENDM

sleep_148 MACRO
	nop
	jr .j0783\@ ; 12t, 2 bytes
.j0783\@:
	jr .j0784\@ ; 12t, 2 bytes
.j0784\@:
	jr .j0785\@ ; 12t, 2 bytes
.j0785\@:
	jr .j0786\@ ; 12t, 2 bytes
.j0786\@:
	jr .j0787\@ ; 12t, 2 bytes
.j0787\@:
	jr .j0788\@ ; 12t, 2 bytes
.j0788\@:
	jr .j0789\@ ; 12t, 2 bytes
.j0789\@:
	jr .j0790\@ ; 12t, 2 bytes
.j0790\@:
	jr .j0791\@ ; 12t, 2 bytes
.j0791\@:
	jr .j0792\@ ; 12t, 2 bytes
.j0792\@:
	jr .j0793\@ ; 12t, 2 bytes
.j0793\@:
	jr .j0794\@ ; 12t, 2 bytes
.j0794\@:
	ENDM

sleep_149 MACRO
	or 0
	jp .j0795\@ ; 10t, 3 bytes
.j0795\@:
	jr .j0796\@ ; 12t, 2 bytes
.j0796\@:
	jr .j0797\@ ; 12t, 2 bytes
.j0797\@:
	jr .j0798\@ ; 12t, 2 bytes
.j0798\@:
	jr .j0799\@ ; 12t, 2 bytes
.j0799\@:
	jr .j0800\@ ; 12t, 2 bytes
.j0800\@:
	jr .j0801\@ ; 12t, 2 bytes
.j0801\@:
	jr .j0802\@ ; 12t, 2 bytes
.j0802\@:
	jr .j0803\@ ; 12t, 2 bytes
.j0803\@:
	jr .j0804\@ ; 12t, 2 bytes
.j0804\@:
	jr .j0805\@ ; 12t, 2 bytes
.j0805\@:
	jr .j0806\@ ; 12t, 2 bytes
.j0806\@:
	ENDM

sleep_150 MACRO
	nop
	or 0
	or 0
	jr .j0807\@ ; 12t, 2 bytes
.j0807\@:
	jr .j0808\@ ; 12t, 2 bytes
.j0808\@:
	jr .j0809\@ ; 12t, 2 bytes
.j0809\@:
	jr .j0810\@ ; 12t, 2 bytes
.j0810\@:
	jr .j0811\@ ; 12t, 2 bytes
.j0811\@:
	jr .j0812\@ ; 12t, 2 bytes
.j0812\@:
	jr .j0813\@ ; 12t, 2 bytes
.j0813\@:
	jr .j0814\@ ; 12t, 2 bytes
.j0814\@:
	jr .j0815\@ ; 12t, 2 bytes
.j0815\@:
	jr .j0816\@ ; 12t, 2 bytes
.j0816\@:
	jr .j0817\@ ; 12t, 2 bytes
.j0817\@:
	ENDM

sleep_151 MACRO
	or 0
	jr .j0818\@ ; 12t, 2 bytes
.j0818\@:
	jr .j0819\@ ; 12t, 2 bytes
.j0819\@:
	jr .j0820\@ ; 12t, 2 bytes
.j0820\@:
	jr .j0821\@ ; 12t, 2 bytes
.j0821\@:
	jr .j0822\@ ; 12t, 2 bytes
.j0822\@:
	jr .j0823\@ ; 12t, 2 bytes
.j0823\@:
	jr .j0824\@ ; 12t, 2 bytes
.j0824\@:
	jr .j0825\@ ; 12t, 2 bytes
.j0825\@:
	jr .j0826\@ ; 12t, 2 bytes
.j0826\@:
	jr .j0827\@ ; 12t, 2 bytes
.j0827\@:
	jr .j0828\@ ; 12t, 2 bytes
.j0828\@:
	jr .j0829\@ ; 12t, 2 bytes
.j0829\@:
	ENDM

sleep_152 MACRO
	nop
	nop
	jr .j0830\@ ; 12t, 2 bytes
.j0830\@:
	jr .j0831\@ ; 12t, 2 bytes
.j0831\@:
	jr .j0832\@ ; 12t, 2 bytes
.j0832\@:
	jr .j0833\@ ; 12t, 2 bytes
.j0833\@:
	jr .j0834\@ ; 12t, 2 bytes
.j0834\@:
	jr .j0835\@ ; 12t, 2 bytes
.j0835\@:
	jr .j0836\@ ; 12t, 2 bytes
.j0836\@:
	jr .j0837\@ ; 12t, 2 bytes
.j0837\@:
	jr .j0838\@ ; 12t, 2 bytes
.j0838\@:
	jr .j0839\@ ; 12t, 2 bytes
.j0839\@:
	jr .j0840\@ ; 12t, 2 bytes
.j0840\@:
	jr .j0841\@ ; 12t, 2 bytes
.j0841\@:
	ENDM

sleep_153 MACRO
	or 0
	or 0
	or 0
	jr .j0842\@ ; 12t, 2 bytes
.j0842\@:
	jr .j0843\@ ; 12t, 2 bytes
.j0843\@:
	jr .j0844\@ ; 12t, 2 bytes
.j0844\@:
	jr .j0845\@ ; 12t, 2 bytes
.j0845\@:
	jr .j0846\@ ; 12t, 2 bytes
.j0846\@:
	jr .j0847\@ ; 12t, 2 bytes
.j0847\@:
	jr .j0848\@ ; 12t, 2 bytes
.j0848\@:
	jr .j0849\@ ; 12t, 2 bytes
.j0849\@:
	jr .j0850\@ ; 12t, 2 bytes
.j0850\@:
	jr .j0851\@ ; 12t, 2 bytes
.j0851\@:
	jr .j0852\@ ; 12t, 2 bytes
.j0852\@:
	ENDM

sleep_154 MACRO
	jp .j0853\@ ; 10t, 3 bytes
.j0853\@:
	jr .j0854\@ ; 12t, 2 bytes
.j0854\@:
	jr .j0855\@ ; 12t, 2 bytes
.j0855\@:
	jr .j0856\@ ; 12t, 2 bytes
.j0856\@:
	jr .j0857\@ ; 12t, 2 bytes
.j0857\@:
	jr .j0858\@ ; 12t, 2 bytes
.j0858\@:
	jr .j0859\@ ; 12t, 2 bytes
.j0859\@:
	jr .j0860\@ ; 12t, 2 bytes
.j0860\@:
	jr .j0861\@ ; 12t, 2 bytes
.j0861\@:
	jr .j0862\@ ; 12t, 2 bytes
.j0862\@:
	jr .j0863\@ ; 12t, 2 bytes
.j0863\@:
	jr .j0864\@ ; 12t, 2 bytes
.j0864\@:
	jr .j0865\@ ; 12t, 2 bytes
.j0865\@:
	ENDM

sleep_155 MACRO
	nop
	or 0
	jr .j0866\@ ; 12t, 2 bytes
.j0866\@:
	jr .j0867\@ ; 12t, 2 bytes
.j0867\@:
	jr .j0868\@ ; 12t, 2 bytes
.j0868\@:
	jr .j0869\@ ; 12t, 2 bytes
.j0869\@:
	jr .j0870\@ ; 12t, 2 bytes
.j0870\@:
	jr .j0871\@ ; 12t, 2 bytes
.j0871\@:
	jr .j0872\@ ; 12t, 2 bytes
.j0872\@:
	jr .j0873\@ ; 12t, 2 bytes
.j0873\@:
	jr .j0874\@ ; 12t, 2 bytes
.j0874\@:
	jr .j0875\@ ; 12t, 2 bytes
.j0875\@:
	jr .j0876\@ ; 12t, 2 bytes
.j0876\@:
	jr .j0877\@ ; 12t, 2 bytes
.j0877\@:
	ENDM

sleep_156 MACRO
	jr .j0878\@ ; 12t, 2 bytes
.j0878\@:
	jr .j0879\@ ; 12t, 2 bytes
.j0879\@:
	jr .j0880\@ ; 12t, 2 bytes
.j0880\@:
	jr .j0881\@ ; 12t, 2 bytes
.j0881\@:
	jr .j0882\@ ; 12t, 2 bytes
.j0882\@:
	jr .j0883\@ ; 12t, 2 bytes
.j0883\@:
	jr .j0884\@ ; 12t, 2 bytes
.j0884\@:
	jr .j0885\@ ; 12t, 2 bytes
.j0885\@:
	jr .j0886\@ ; 12t, 2 bytes
.j0886\@:
	jr .j0887\@ ; 12t, 2 bytes
.j0887\@:
	jr .j0888\@ ; 12t, 2 bytes
.j0888\@:
	jr .j0889\@ ; 12t, 2 bytes
.j0889\@:
	jr .j0890\@ ; 12t, 2 bytes
.j0890\@:
	ENDM

sleep_157 MACRO
	nop
	or 0
	or 0
	or 0
	jr .j0891\@ ; 12t, 2 bytes
.j0891\@:
	jr .j0892\@ ; 12t, 2 bytes
.j0892\@:
	jr .j0893\@ ; 12t, 2 bytes
.j0893\@:
	jr .j0894\@ ; 12t, 2 bytes
.j0894\@:
	jr .j0895\@ ; 12t, 2 bytes
.j0895\@:
	jr .j0896\@ ; 12t, 2 bytes
.j0896\@:
	jr .j0897\@ ; 12t, 2 bytes
.j0897\@:
	jr .j0898\@ ; 12t, 2 bytes
.j0898\@:
	jr .j0899\@ ; 12t, 2 bytes
.j0899\@:
	jr .j0900\@ ; 12t, 2 bytes
.j0900\@:
	jr .j0901\@ ; 12t, 2 bytes
.j0901\@:
	ENDM

sleep_158 MACRO
	or 0
	or 0
	jr .j0902\@ ; 12t, 2 bytes
.j0902\@:
	jr .j0903\@ ; 12t, 2 bytes
.j0903\@:
	jr .j0904\@ ; 12t, 2 bytes
.j0904\@:
	jr .j0905\@ ; 12t, 2 bytes
.j0905\@:
	jr .j0906\@ ; 12t, 2 bytes
.j0906\@:
	jr .j0907\@ ; 12t, 2 bytes
.j0907\@:
	jr .j0908\@ ; 12t, 2 bytes
.j0908\@:
	jr .j0909\@ ; 12t, 2 bytes
.j0909\@:
	jr .j0910\@ ; 12t, 2 bytes
.j0910\@:
	jr .j0911\@ ; 12t, 2 bytes
.j0911\@:
	jr .j0912\@ ; 12t, 2 bytes
.j0912\@:
	jr .j0913\@ ; 12t, 2 bytes
.j0913\@:
	ENDM

sleep_159 MACRO
	nop
	nop
	or 0
	jr .j0914\@ ; 12t, 2 bytes
.j0914\@:
	jr .j0915\@ ; 12t, 2 bytes
.j0915\@:
	jr .j0916\@ ; 12t, 2 bytes
.j0916\@:
	jr .j0917\@ ; 12t, 2 bytes
.j0917\@:
	jr .j0918\@ ; 12t, 2 bytes
.j0918\@:
	jr .j0919\@ ; 12t, 2 bytes
.j0919\@:
	jr .j0920\@ ; 12t, 2 bytes
.j0920\@:
	jr .j0921\@ ; 12t, 2 bytes
.j0921\@:
	jr .j0922\@ ; 12t, 2 bytes
.j0922\@:
	jr .j0923\@ ; 12t, 2 bytes
.j0923\@:
	jr .j0924\@ ; 12t, 2 bytes
.j0924\@:
	jr .j0925\@ ; 12t, 2 bytes
.j0925\@:
	ENDM

sleep_160 MACRO
	nop
	jr .j0926\@ ; 12t, 2 bytes
.j0926\@:
	jr .j0927\@ ; 12t, 2 bytes
.j0927\@:
	jr .j0928\@ ; 12t, 2 bytes
.j0928\@:
	jr .j0929\@ ; 12t, 2 bytes
.j0929\@:
	jr .j0930\@ ; 12t, 2 bytes
.j0930\@:
	jr .j0931\@ ; 12t, 2 bytes
.j0931\@:
	jr .j0932\@ ; 12t, 2 bytes
.j0932\@:
	jr .j0933\@ ; 12t, 2 bytes
.j0933\@:
	jr .j0934\@ ; 12t, 2 bytes
.j0934\@:
	jr .j0935\@ ; 12t, 2 bytes
.j0935\@:
	jr .j0936\@ ; 12t, 2 bytes
.j0936\@:
	jr .j0937\@ ; 12t, 2 bytes
.j0937\@:
	jr .j0938\@ ; 12t, 2 bytes
.j0938\@:
	ENDM

sleep_161 MACRO
	or 0
	jp .j0939\@ ; 10t, 3 bytes
.j0939\@:
	jr .j0940\@ ; 12t, 2 bytes
.j0940\@:
	jr .j0941\@ ; 12t, 2 bytes
.j0941\@:
	jr .j0942\@ ; 12t, 2 bytes
.j0942\@:
	jr .j0943\@ ; 12t, 2 bytes
.j0943\@:
	jr .j0944\@ ; 12t, 2 bytes
.j0944\@:
	jr .j0945\@ ; 12t, 2 bytes
.j0945\@:
	jr .j0946\@ ; 12t, 2 bytes
.j0946\@:
	jr .j0947\@ ; 12t, 2 bytes
.j0947\@:
	jr .j0948\@ ; 12t, 2 bytes
.j0948\@:
	jr .j0949\@ ; 12t, 2 bytes
.j0949\@:
	jr .j0950\@ ; 12t, 2 bytes
.j0950\@:
	jr .j0951\@ ; 12t, 2 bytes
.j0951\@:
	ENDM

sleep_162 MACRO
	nop
	or 0
	or 0
	jr .j0952\@ ; 12t, 2 bytes
.j0952\@:
	jr .j0953\@ ; 12t, 2 bytes
.j0953\@:
	jr .j0954\@ ; 12t, 2 bytes
.j0954\@:
	jr .j0955\@ ; 12t, 2 bytes
.j0955\@:
	jr .j0956\@ ; 12t, 2 bytes
.j0956\@:
	jr .j0957\@ ; 12t, 2 bytes
.j0957\@:
	jr .j0958\@ ; 12t, 2 bytes
.j0958\@:
	jr .j0959\@ ; 12t, 2 bytes
.j0959\@:
	jr .j0960\@ ; 12t, 2 bytes
.j0960\@:
	jr .j0961\@ ; 12t, 2 bytes
.j0961\@:
	jr .j0962\@ ; 12t, 2 bytes
.j0962\@:
	jr .j0963\@ ; 12t, 2 bytes
.j0963\@:
	ENDM

sleep_163 MACRO
	or 0
	jr .j0964\@ ; 12t, 2 bytes
.j0964\@:
	jr .j0965\@ ; 12t, 2 bytes
.j0965\@:
	jr .j0966\@ ; 12t, 2 bytes
.j0966\@:
	jr .j0967\@ ; 12t, 2 bytes
.j0967\@:
	jr .j0968\@ ; 12t, 2 bytes
.j0968\@:
	jr .j0969\@ ; 12t, 2 bytes
.j0969\@:
	jr .j0970\@ ; 12t, 2 bytes
.j0970\@:
	jr .j0971\@ ; 12t, 2 bytes
.j0971\@:
	jr .j0972\@ ; 12t, 2 bytes
.j0972\@:
	jr .j0973\@ ; 12t, 2 bytes
.j0973\@:
	jr .j0974\@ ; 12t, 2 bytes
.j0974\@:
	jr .j0975\@ ; 12t, 2 bytes
.j0975\@:
	jr .j0976\@ ; 12t, 2 bytes
.j0976\@:
	ENDM

sleep_164 MACRO
	nop
	nop
	jr .j0977\@ ; 12t, 2 bytes
.j0977\@:
	jr .j0978\@ ; 12t, 2 bytes
.j0978\@:
	jr .j0979\@ ; 12t, 2 bytes
.j0979\@:
	jr .j0980\@ ; 12t, 2 bytes
.j0980\@:
	jr .j0981\@ ; 12t, 2 bytes
.j0981\@:
	jr .j0982\@ ; 12t, 2 bytes
.j0982\@:
	jr .j0983\@ ; 12t, 2 bytes
.j0983\@:
	jr .j0984\@ ; 12t, 2 bytes
.j0984\@:
	jr .j0985\@ ; 12t, 2 bytes
.j0985\@:
	jr .j0986\@ ; 12t, 2 bytes
.j0986\@:
	jr .j0987\@ ; 12t, 2 bytes
.j0987\@:
	jr .j0988\@ ; 12t, 2 bytes
.j0988\@:
	jr .j0989\@ ; 12t, 2 bytes
.j0989\@:
	ENDM

sleep_165 MACRO
	or 0
	or 0
	or 0
	jr .j0990\@ ; 12t, 2 bytes
.j0990\@:
	jr .j0991\@ ; 12t, 2 bytes
.j0991\@:
	jr .j0992\@ ; 12t, 2 bytes
.j0992\@:
	jr .j0993\@ ; 12t, 2 bytes
.j0993\@:
	jr .j0994\@ ; 12t, 2 bytes
.j0994\@:
	jr .j0995\@ ; 12t, 2 bytes
.j0995\@:
	jr .j0996\@ ; 12t, 2 bytes
.j0996\@:
	jr .j0997\@ ; 12t, 2 bytes
.j0997\@:
	jr .j0998\@ ; 12t, 2 bytes
.j0998\@:
	jr .j0999\@ ; 12t, 2 bytes
.j0999\@:
	jr .j1000\@ ; 12t, 2 bytes
.j1000\@:
	jr .j1001\@ ; 12t, 2 bytes
.j1001\@:
	ENDM

sleep_166 MACRO
	jp .j1002\@ ; 10t, 3 bytes
.j1002\@:
	jr .j1003\@ ; 12t, 2 bytes
.j1003\@:
	jr .j1004\@ ; 12t, 2 bytes
.j1004\@:
	jr .j1005\@ ; 12t, 2 bytes
.j1005\@:
	jr .j1006\@ ; 12t, 2 bytes
.j1006\@:
	jr .j1007\@ ; 12t, 2 bytes
.j1007\@:
	jr .j1008\@ ; 12t, 2 bytes
.j1008\@:
	jr .j1009\@ ; 12t, 2 bytes
.j1009\@:
	jr .j1010\@ ; 12t, 2 bytes
.j1010\@:
	jr .j1011\@ ; 12t, 2 bytes
.j1011\@:
	jr .j1012\@ ; 12t, 2 bytes
.j1012\@:
	jr .j1013\@ ; 12t, 2 bytes
.j1013\@:
	jr .j1014\@ ; 12t, 2 bytes
.j1014\@:
	jr .j1015\@ ; 12t, 2 bytes
.j1015\@:
	ENDM

sleep_167 MACRO
	nop
	or 0
	jr .j1016\@ ; 12t, 2 bytes
.j1016\@:
	jr .j1017\@ ; 12t, 2 bytes
.j1017\@:
	jr .j1018\@ ; 12t, 2 bytes
.j1018\@:
	jr .j1019\@ ; 12t, 2 bytes
.j1019\@:
	jr .j1020\@ ; 12t, 2 bytes
.j1020\@:
	jr .j1021\@ ; 12t, 2 bytes
.j1021\@:
	jr .j1022\@ ; 12t, 2 bytes
.j1022\@:
	jr .j1023\@ ; 12t, 2 bytes
.j1023\@:
	jr .j1024\@ ; 12t, 2 bytes
.j1024\@:
	jr .j1025\@ ; 12t, 2 bytes
.j1025\@:
	jr .j1026\@ ; 12t, 2 bytes
.j1026\@:
	jr .j1027\@ ; 12t, 2 bytes
.j1027\@:
	jr .j1028\@ ; 12t, 2 bytes
.j1028\@:
	ENDM

sleep_168 MACRO
	jr .j1029\@ ; 12t, 2 bytes
.j1029\@:
	jr .j1030\@ ; 12t, 2 bytes
.j1030\@:
	jr .j1031\@ ; 12t, 2 bytes
.j1031\@:
	jr .j1032\@ ; 12t, 2 bytes
.j1032\@:
	jr .j1033\@ ; 12t, 2 bytes
.j1033\@:
	jr .j1034\@ ; 12t, 2 bytes
.j1034\@:
	jr .j1035\@ ; 12t, 2 bytes
.j1035\@:
	jr .j1036\@ ; 12t, 2 bytes
.j1036\@:
	jr .j1037\@ ; 12t, 2 bytes
.j1037\@:
	jr .j1038\@ ; 12t, 2 bytes
.j1038\@:
	jr .j1039\@ ; 12t, 2 bytes
.j1039\@:
	jr .j1040\@ ; 12t, 2 bytes
.j1040\@:
	jr .j1041\@ ; 12t, 2 bytes
.j1041\@:
	jr .j1042\@ ; 12t, 2 bytes
.j1042\@:
	ENDM

sleep_169 MACRO
	nop
	or 0
	or 0
	or 0
	jr .j1043\@ ; 12t, 2 bytes
.j1043\@:
	jr .j1044\@ ; 12t, 2 bytes
.j1044\@:
	jr .j1045\@ ; 12t, 2 bytes
.j1045\@:
	jr .j1046\@ ; 12t, 2 bytes
.j1046\@:
	jr .j1047\@ ; 12t, 2 bytes
.j1047\@:
	jr .j1048\@ ; 12t, 2 bytes
.j1048\@:
	jr .j1049\@ ; 12t, 2 bytes
.j1049\@:
	jr .j1050\@ ; 12t, 2 bytes
.j1050\@:
	jr .j1051\@ ; 12t, 2 bytes
.j1051\@:
	jr .j1052\@ ; 12t, 2 bytes
.j1052\@:
	jr .j1053\@ ; 12t, 2 bytes
.j1053\@:
	jr .j1054\@ ; 12t, 2 bytes
.j1054\@:
	ENDM

sleep_170 MACRO
	or 0
	or 0
	jr .j1055\@ ; 12t, 2 bytes
.j1055\@:
	jr .j1056\@ ; 12t, 2 bytes
.j1056\@:
	jr .j1057\@ ; 12t, 2 bytes
.j1057\@:
	jr .j1058\@ ; 12t, 2 bytes
.j1058\@:
	jr .j1059\@ ; 12t, 2 bytes
.j1059\@:
	jr .j1060\@ ; 12t, 2 bytes
.j1060\@:
	jr .j1061\@ ; 12t, 2 bytes
.j1061\@:
	jr .j1062\@ ; 12t, 2 bytes
.j1062\@:
	jr .j1063\@ ; 12t, 2 bytes
.j1063\@:
	jr .j1064\@ ; 12t, 2 bytes
.j1064\@:
	jr .j1065\@ ; 12t, 2 bytes
.j1065\@:
	jr .j1066\@ ; 12t, 2 bytes
.j1066\@:
	jr .j1067\@ ; 12t, 2 bytes
.j1067\@:
	ENDM

sleep_171 MACRO
	nop
	nop
	or 0
	jr .j1068\@ ; 12t, 2 bytes
.j1068\@:
	jr .j1069\@ ; 12t, 2 bytes
.j1069\@:
	jr .j1070\@ ; 12t, 2 bytes
.j1070\@:
	jr .j1071\@ ; 12t, 2 bytes
.j1071\@:
	jr .j1072\@ ; 12t, 2 bytes
.j1072\@:
	jr .j1073\@ ; 12t, 2 bytes
.j1073\@:
	jr .j1074\@ ; 12t, 2 bytes
.j1074\@:
	jr .j1075\@ ; 12t, 2 bytes
.j1075\@:
	jr .j1076\@ ; 12t, 2 bytes
.j1076\@:
	jr .j1077\@ ; 12t, 2 bytes
.j1077\@:
	jr .j1078\@ ; 12t, 2 bytes
.j1078\@:
	jr .j1079\@ ; 12t, 2 bytes
.j1079\@:
	jr .j1080\@ ; 12t, 2 bytes
.j1080\@:
	ENDM

sleep_172 MACRO
	nop
	jr .j1081\@ ; 12t, 2 bytes
.j1081\@:
	jr .j1082\@ ; 12t, 2 bytes
.j1082\@:
	jr .j1083\@ ; 12t, 2 bytes
.j1083\@:
	jr .j1084\@ ; 12t, 2 bytes
.j1084\@:
	jr .j1085\@ ; 12t, 2 bytes
.j1085\@:
	jr .j1086\@ ; 12t, 2 bytes
.j1086\@:
	jr .j1087\@ ; 12t, 2 bytes
.j1087\@:
	jr .j1088\@ ; 12t, 2 bytes
.j1088\@:
	jr .j1089\@ ; 12t, 2 bytes
.j1089\@:
	jr .j1090\@ ; 12t, 2 bytes
.j1090\@:
	jr .j1091\@ ; 12t, 2 bytes
.j1091\@:
	jr .j1092\@ ; 12t, 2 bytes
.j1092\@:
	jr .j1093\@ ; 12t, 2 bytes
.j1093\@:
	jr .j1094\@ ; 12t, 2 bytes
.j1094\@:
	ENDM

sleep_173 MACRO
	or 0
	jp .j1095\@ ; 10t, 3 bytes
.j1095\@:
	jr .j1096\@ ; 12t, 2 bytes
.j1096\@:
	jr .j1097\@ ; 12t, 2 bytes
.j1097\@:
	jr .j1098\@ ; 12t, 2 bytes
.j1098\@:
	jr .j1099\@ ; 12t, 2 bytes
.j1099\@:
	jr .j1100\@ ; 12t, 2 bytes
.j1100\@:
	jr .j1101\@ ; 12t, 2 bytes
.j1101\@:
	jr .j1102\@ ; 12t, 2 bytes
.j1102\@:
	jr .j1103\@ ; 12t, 2 bytes
.j1103\@:
	jr .j1104\@ ; 12t, 2 bytes
.j1104\@:
	jr .j1105\@ ; 12t, 2 bytes
.j1105\@:
	jr .j1106\@ ; 12t, 2 bytes
.j1106\@:
	jr .j1107\@ ; 12t, 2 bytes
.j1107\@:
	jr .j1108\@ ; 12t, 2 bytes
.j1108\@:
	ENDM

sleep_174 MACRO
	nop
	or 0
	or 0
	jr .j1109\@ ; 12t, 2 bytes
.j1109\@:
	jr .j1110\@ ; 12t, 2 bytes
.j1110\@:
	jr .j1111\@ ; 12t, 2 bytes
.j1111\@:
	jr .j1112\@ ; 12t, 2 bytes
.j1112\@:
	jr .j1113\@ ; 12t, 2 bytes
.j1113\@:
	jr .j1114\@ ; 12t, 2 bytes
.j1114\@:
	jr .j1115\@ ; 12t, 2 bytes
.j1115\@:
	jr .j1116\@ ; 12t, 2 bytes
.j1116\@:
	jr .j1117\@ ; 12t, 2 bytes
.j1117\@:
	jr .j1118\@ ; 12t, 2 bytes
.j1118\@:
	jr .j1119\@ ; 12t, 2 bytes
.j1119\@:
	jr .j1120\@ ; 12t, 2 bytes
.j1120\@:
	jr .j1121\@ ; 12t, 2 bytes
.j1121\@:
	ENDM

sleep_175 MACRO
	or 0
	jr .j1122\@ ; 12t, 2 bytes
.j1122\@:
	jr .j1123\@ ; 12t, 2 bytes
.j1123\@:
	jr .j1124\@ ; 12t, 2 bytes
.j1124\@:
	jr .j1125\@ ; 12t, 2 bytes
.j1125\@:
	jr .j1126\@ ; 12t, 2 bytes
.j1126\@:
	jr .j1127\@ ; 12t, 2 bytes
.j1127\@:
	jr .j1128\@ ; 12t, 2 bytes
.j1128\@:
	jr .j1129\@ ; 12t, 2 bytes
.j1129\@:
	jr .j1130\@ ; 12t, 2 bytes
.j1130\@:
	jr .j1131\@ ; 12t, 2 bytes
.j1131\@:
	jr .j1132\@ ; 12t, 2 bytes
.j1132\@:
	jr .j1133\@ ; 12t, 2 bytes
.j1133\@:
	jr .j1134\@ ; 12t, 2 bytes
.j1134\@:
	jr .j1135\@ ; 12t, 2 bytes
.j1135\@:
	ENDM

sleep_176 MACRO
	nop
	nop
	jr .j1136\@ ; 12t, 2 bytes
.j1136\@:
	jr .j1137\@ ; 12t, 2 bytes
.j1137\@:
	jr .j1138\@ ; 12t, 2 bytes
.j1138\@:
	jr .j1139\@ ; 12t, 2 bytes
.j1139\@:
	jr .j1140\@ ; 12t, 2 bytes
.j1140\@:
	jr .j1141\@ ; 12t, 2 bytes
.j1141\@:
	jr .j1142\@ ; 12t, 2 bytes
.j1142\@:
	jr .j1143\@ ; 12t, 2 bytes
.j1143\@:
	jr .j1144\@ ; 12t, 2 bytes
.j1144\@:
	jr .j1145\@ ; 12t, 2 bytes
.j1145\@:
	jr .j1146\@ ; 12t, 2 bytes
.j1146\@:
	jr .j1147\@ ; 12t, 2 bytes
.j1147\@:
	jr .j1148\@ ; 12t, 2 bytes
.j1148\@:
	jr .j1149\@ ; 12t, 2 bytes
.j1149\@:
	ENDM

sleep_177 MACRO
	or 0
	or 0
	or 0
	jr .j1150\@ ; 12t, 2 bytes
.j1150\@:
	jr .j1151\@ ; 12t, 2 bytes
.j1151\@:
	jr .j1152\@ ; 12t, 2 bytes
.j1152\@:
	jr .j1153\@ ; 12t, 2 bytes
.j1153\@:
	jr .j1154\@ ; 12t, 2 bytes
.j1154\@:
	jr .j1155\@ ; 12t, 2 bytes
.j1155\@:
	jr .j1156\@ ; 12t, 2 bytes
.j1156\@:
	jr .j1157\@ ; 12t, 2 bytes
.j1157\@:
	jr .j1158\@ ; 12t, 2 bytes
.j1158\@:
	jr .j1159\@ ; 12t, 2 bytes
.j1159\@:
	jr .j1160\@ ; 12t, 2 bytes
.j1160\@:
	jr .j1161\@ ; 12t, 2 bytes
.j1161\@:
	jr .j1162\@ ; 12t, 2 bytes
.j1162\@:
	ENDM

sleep_178 MACRO
	jp .j1163\@ ; 10t, 3 bytes
.j1163\@:
	jr .j1164\@ ; 12t, 2 bytes
.j1164\@:
	jr .j1165\@ ; 12t, 2 bytes
.j1165\@:
	jr .j1166\@ ; 12t, 2 bytes
.j1166\@:
	jr .j1167\@ ; 12t, 2 bytes
.j1167\@:
	jr .j1168\@ ; 12t, 2 bytes
.j1168\@:
	jr .j1169\@ ; 12t, 2 bytes
.j1169\@:
	jr .j1170\@ ; 12t, 2 bytes
.j1170\@:
	jr .j1171\@ ; 12t, 2 bytes
.j1171\@:
	jr .j1172\@ ; 12t, 2 bytes
.j1172\@:
	jr .j1173\@ ; 12t, 2 bytes
.j1173\@:
	jr .j1174\@ ; 12t, 2 bytes
.j1174\@:
	jr .j1175\@ ; 12t, 2 bytes
.j1175\@:
	jr .j1176\@ ; 12t, 2 bytes
.j1176\@:
	jr .j1177\@ ; 12t, 2 bytes
.j1177\@:
	ENDM

sleep_179 MACRO
	nop
	or 0
	jr .j1178\@ ; 12t, 2 bytes
.j1178\@:
	jr .j1179\@ ; 12t, 2 bytes
.j1179\@:
	jr .j1180\@ ; 12t, 2 bytes
.j1180\@:
	jr .j1181\@ ; 12t, 2 bytes
.j1181\@:
	jr .j1182\@ ; 12t, 2 bytes
.j1182\@:
	jr .j1183\@ ; 12t, 2 bytes
.j1183\@:
	jr .j1184\@ ; 12t, 2 bytes
.j1184\@:
	jr .j1185\@ ; 12t, 2 bytes
.j1185\@:
	jr .j1186\@ ; 12t, 2 bytes
.j1186\@:
	jr .j1187\@ ; 12t, 2 bytes
.j1187\@:
	jr .j1188\@ ; 12t, 2 bytes
.j1188\@:
	jr .j1189\@ ; 12t, 2 bytes
.j1189\@:
	jr .j1190\@ ; 12t, 2 bytes
.j1190\@:
	jr .j1191\@ ; 12t, 2 bytes
.j1191\@:
	ENDM

sleep_180 MACRO
	jr .j1192\@ ; 12t, 2 bytes
.j1192\@:
	jr .j1193\@ ; 12t, 2 bytes
.j1193\@:
	jr .j1194\@ ; 12t, 2 bytes
.j1194\@:
	jr .j1195\@ ; 12t, 2 bytes
.j1195\@:
	jr .j1196\@ ; 12t, 2 bytes
.j1196\@:
	jr .j1197\@ ; 12t, 2 bytes
.j1197\@:
	jr .j1198\@ ; 12t, 2 bytes
.j1198\@:
	jr .j1199\@ ; 12t, 2 bytes
.j1199\@:
	jr .j1200\@ ; 12t, 2 bytes
.j1200\@:
	jr .j1201\@ ; 12t, 2 bytes
.j1201\@:
	jr .j1202\@ ; 12t, 2 bytes
.j1202\@:
	jr .j1203\@ ; 12t, 2 bytes
.j1203\@:
	jr .j1204\@ ; 12t, 2 bytes
.j1204\@:
	jr .j1205\@ ; 12t, 2 bytes
.j1205\@:
	jr .j1206\@ ; 12t, 2 bytes
.j1206\@:
	ENDM

sleep_181 MACRO
	nop
	or 0
	or 0
	or 0
	jr .j1207\@ ; 12t, 2 bytes
.j1207\@:
	jr .j1208\@ ; 12t, 2 bytes
.j1208\@:
	jr .j1209\@ ; 12t, 2 bytes
.j1209\@:
	jr .j1210\@ ; 12t, 2 bytes
.j1210\@:
	jr .j1211\@ ; 12t, 2 bytes
.j1211\@:
	jr .j1212\@ ; 12t, 2 bytes
.j1212\@:
	jr .j1213\@ ; 12t, 2 bytes
.j1213\@:
	jr .j1214\@ ; 12t, 2 bytes
.j1214\@:
	jr .j1215\@ ; 12t, 2 bytes
.j1215\@:
	jr .j1216\@ ; 12t, 2 bytes
.j1216\@:
	jr .j1217\@ ; 12t, 2 bytes
.j1217\@:
	jr .j1218\@ ; 12t, 2 bytes
.j1218\@:
	jr .j1219\@ ; 12t, 2 bytes
.j1219\@:
	ENDM

sleep_182 MACRO
	or 0
	or 0
	jr .j1220\@ ; 12t, 2 bytes
.j1220\@:
	jr .j1221\@ ; 12t, 2 bytes
.j1221\@:
	jr .j1222\@ ; 12t, 2 bytes
.j1222\@:
	jr .j1223\@ ; 12t, 2 bytes
.j1223\@:
	jr .j1224\@ ; 12t, 2 bytes
.j1224\@:
	jr .j1225\@ ; 12t, 2 bytes
.j1225\@:
	jr .j1226\@ ; 12t, 2 bytes
.j1226\@:
	jr .j1227\@ ; 12t, 2 bytes
.j1227\@:
	jr .j1228\@ ; 12t, 2 bytes
.j1228\@:
	jr .j1229\@ ; 12t, 2 bytes
.j1229\@:
	jr .j1230\@ ; 12t, 2 bytes
.j1230\@:
	jr .j1231\@ ; 12t, 2 bytes
.j1231\@:
	jr .j1232\@ ; 12t, 2 bytes
.j1232\@:
	jr .j1233\@ ; 12t, 2 bytes
.j1233\@:
	ENDM

sleep_183 MACRO
	nop
	nop
	or 0
	jr .j1234\@ ; 12t, 2 bytes
.j1234\@:
	jr .j1235\@ ; 12t, 2 bytes
.j1235\@:
	jr .j1236\@ ; 12t, 2 bytes
.j1236\@:
	jr .j1237\@ ; 12t, 2 bytes
.j1237\@:
	jr .j1238\@ ; 12t, 2 bytes
.j1238\@:
	jr .j1239\@ ; 12t, 2 bytes
.j1239\@:
	jr .j1240\@ ; 12t, 2 bytes
.j1240\@:
	jr .j1241\@ ; 12t, 2 bytes
.j1241\@:
	jr .j1242\@ ; 12t, 2 bytes
.j1242\@:
	jr .j1243\@ ; 12t, 2 bytes
.j1243\@:
	jr .j1244\@ ; 12t, 2 bytes
.j1244\@:
	jr .j1245\@ ; 12t, 2 bytes
.j1245\@:
	jr .j1246\@ ; 12t, 2 bytes
.j1246\@:
	jr .j1247\@ ; 12t, 2 bytes
.j1247\@:
	ENDM

sleep_184 MACRO
	nop
	jr .j1248\@ ; 12t, 2 bytes
.j1248\@:
	jr .j1249\@ ; 12t, 2 bytes
.j1249\@:
	jr .j1250\@ ; 12t, 2 bytes
.j1250\@:
	jr .j1251\@ ; 12t, 2 bytes
.j1251\@:
	jr .j1252\@ ; 12t, 2 bytes
.j1252\@:
	jr .j1253\@ ; 12t, 2 bytes
.j1253\@:
	jr .j1254\@ ; 12t, 2 bytes
.j1254\@:
	jr .j1255\@ ; 12t, 2 bytes
.j1255\@:
	jr .j1256\@ ; 12t, 2 bytes
.j1256\@:
	jr .j1257\@ ; 12t, 2 bytes
.j1257\@:
	jr .j1258\@ ; 12t, 2 bytes
.j1258\@:
	jr .j1259\@ ; 12t, 2 bytes
.j1259\@:
	jr .j1260\@ ; 12t, 2 bytes
.j1260\@:
	jr .j1261\@ ; 12t, 2 bytes
.j1261\@:
	jr .j1262\@ ; 12t, 2 bytes
.j1262\@:
	ENDM

sleep_185 MACRO
	or 0
	jp .j1263\@ ; 10t, 3 bytes
.j1263\@:
	jr .j1264\@ ; 12t, 2 bytes
.j1264\@:
	jr .j1265\@ ; 12t, 2 bytes
.j1265\@:
	jr .j1266\@ ; 12t, 2 bytes
.j1266\@:
	jr .j1267\@ ; 12t, 2 bytes
.j1267\@:
	jr .j1268\@ ; 12t, 2 bytes
.j1268\@:
	jr .j1269\@ ; 12t, 2 bytes
.j1269\@:
	jr .j1270\@ ; 12t, 2 bytes
.j1270\@:
	jr .j1271\@ ; 12t, 2 bytes
.j1271\@:
	jr .j1272\@ ; 12t, 2 bytes
.j1272\@:
	jr .j1273\@ ; 12t, 2 bytes
.j1273\@:
	jr .j1274\@ ; 12t, 2 bytes
.j1274\@:
	jr .j1275\@ ; 12t, 2 bytes
.j1275\@:
	jr .j1276\@ ; 12t, 2 bytes
.j1276\@:
	jr .j1277\@ ; 12t, 2 bytes
.j1277\@:
	ENDM

sleep_186 MACRO
	nop
	or 0
	or 0
	jr .j1278\@ ; 12t, 2 bytes
.j1278\@:
	jr .j1279\@ ; 12t, 2 bytes
.j1279\@:
	jr .j1280\@ ; 12t, 2 bytes
.j1280\@:
	jr .j1281\@ ; 12t, 2 bytes
.j1281\@:
	jr .j1282\@ ; 12t, 2 bytes
.j1282\@:
	jr .j1283\@ ; 12t, 2 bytes
.j1283\@:
	jr .j1284\@ ; 12t, 2 bytes
.j1284\@:
	jr .j1285\@ ; 12t, 2 bytes
.j1285\@:
	jr .j1286\@ ; 12t, 2 bytes
.j1286\@:
	jr .j1287\@ ; 12t, 2 bytes
.j1287\@:
	jr .j1288\@ ; 12t, 2 bytes
.j1288\@:
	jr .j1289\@ ; 12t, 2 bytes
.j1289\@:
	jr .j1290\@ ; 12t, 2 bytes
.j1290\@:
	jr .j1291\@ ; 12t, 2 bytes
.j1291\@:
	ENDM

sleep_187 MACRO
	or 0
	jr .j1292\@ ; 12t, 2 bytes
.j1292\@:
	jr .j1293\@ ; 12t, 2 bytes
.j1293\@:
	jr .j1294\@ ; 12t, 2 bytes
.j1294\@:
	jr .j1295\@ ; 12t, 2 bytes
.j1295\@:
	jr .j1296\@ ; 12t, 2 bytes
.j1296\@:
	jr .j1297\@ ; 12t, 2 bytes
.j1297\@:
	jr .j1298\@ ; 12t, 2 bytes
.j1298\@:
	jr .j1299\@ ; 12t, 2 bytes
.j1299\@:
	jr .j1300\@ ; 12t, 2 bytes
.j1300\@:
	jr .j1301\@ ; 12t, 2 bytes
.j1301\@:
	jr .j1302\@ ; 12t, 2 bytes
.j1302\@:
	jr .j1303\@ ; 12t, 2 bytes
.j1303\@:
	jr .j1304\@ ; 12t, 2 bytes
.j1304\@:
	jr .j1305\@ ; 12t, 2 bytes
.j1305\@:
	jr .j1306\@ ; 12t, 2 bytes
.j1306\@:
	ENDM

sleep_188 MACRO
	nop
	nop
	jr .j1307\@ ; 12t, 2 bytes
.j1307\@:
	jr .j1308\@ ; 12t, 2 bytes
.j1308\@:
	jr .j1309\@ ; 12t, 2 bytes
.j1309\@:
	jr .j1310\@ ; 12t, 2 bytes
.j1310\@:
	jr .j1311\@ ; 12t, 2 bytes
.j1311\@:
	jr .j1312\@ ; 12t, 2 bytes
.j1312\@:
	jr .j1313\@ ; 12t, 2 bytes
.j1313\@:
	jr .j1314\@ ; 12t, 2 bytes
.j1314\@:
	jr .j1315\@ ; 12t, 2 bytes
.j1315\@:
	jr .j1316\@ ; 12t, 2 bytes
.j1316\@:
	jr .j1317\@ ; 12t, 2 bytes
.j1317\@:
	jr .j1318\@ ; 12t, 2 bytes
.j1318\@:
	jr .j1319\@ ; 12t, 2 bytes
.j1319\@:
	jr .j1320\@ ; 12t, 2 bytes
.j1320\@:
	jr .j1321\@ ; 12t, 2 bytes
.j1321\@:
	ENDM

sleep_189 MACRO
	or 0
	or 0
	or 0
	jr .j1322\@ ; 12t, 2 bytes
.j1322\@:
	jr .j1323\@ ; 12t, 2 bytes
.j1323\@:
	jr .j1324\@ ; 12t, 2 bytes
.j1324\@:
	jr .j1325\@ ; 12t, 2 bytes
.j1325\@:
	jr .j1326\@ ; 12t, 2 bytes
.j1326\@:
	jr .j1327\@ ; 12t, 2 bytes
.j1327\@:
	jr .j1328\@ ; 12t, 2 bytes
.j1328\@:
	jr .j1329\@ ; 12t, 2 bytes
.j1329\@:
	jr .j1330\@ ; 12t, 2 bytes
.j1330\@:
	jr .j1331\@ ; 12t, 2 bytes
.j1331\@:
	jr .j1332\@ ; 12t, 2 bytes
.j1332\@:
	jr .j1333\@ ; 12t, 2 bytes
.j1333\@:
	jr .j1334\@ ; 12t, 2 bytes
.j1334\@:
	jr .j1335\@ ; 12t, 2 bytes
.j1335\@:
	ENDM

sleep_190 MACRO
	jp .j1336\@ ; 10t, 3 bytes
.j1336\@:
	jr .j1337\@ ; 12t, 2 bytes
.j1337\@:
	jr .j1338\@ ; 12t, 2 bytes
.j1338\@:
	jr .j1339\@ ; 12t, 2 bytes
.j1339\@:
	jr .j1340\@ ; 12t, 2 bytes
.j1340\@:
	jr .j1341\@ ; 12t, 2 bytes
.j1341\@:
	jr .j1342\@ ; 12t, 2 bytes
.j1342\@:
	jr .j1343\@ ; 12t, 2 bytes
.j1343\@:
	jr .j1344\@ ; 12t, 2 bytes
.j1344\@:
	jr .j1345\@ ; 12t, 2 bytes
.j1345\@:
	jr .j1346\@ ; 12t, 2 bytes
.j1346\@:
	jr .j1347\@ ; 12t, 2 bytes
.j1347\@:
	jr .j1348\@ ; 12t, 2 bytes
.j1348\@:
	jr .j1349\@ ; 12t, 2 bytes
.j1349\@:
	jr .j1350\@ ; 12t, 2 bytes
.j1350\@:
	jr .j1351\@ ; 12t, 2 bytes
.j1351\@:
	ENDM

sleep_191 MACRO
	nop
	or 0
	jr .j1352\@ ; 12t, 2 bytes
.j1352\@:
	jr .j1353\@ ; 12t, 2 bytes
.j1353\@:
	jr .j1354\@ ; 12t, 2 bytes
.j1354\@:
	jr .j1355\@ ; 12t, 2 bytes
.j1355\@:
	jr .j1356\@ ; 12t, 2 bytes
.j1356\@:
	jr .j1357\@ ; 12t, 2 bytes
.j1357\@:
	jr .j1358\@ ; 12t, 2 bytes
.j1358\@:
	jr .j1359\@ ; 12t, 2 bytes
.j1359\@:
	jr .j1360\@ ; 12t, 2 bytes
.j1360\@:
	jr .j1361\@ ; 12t, 2 bytes
.j1361\@:
	jr .j1362\@ ; 12t, 2 bytes
.j1362\@:
	jr .j1363\@ ; 12t, 2 bytes
.j1363\@:
	jr .j1364\@ ; 12t, 2 bytes
.j1364\@:
	jr .j1365\@ ; 12t, 2 bytes
.j1365\@:
	jr .j1366\@ ; 12t, 2 bytes
.j1366\@:
	ENDM

sleep_192 MACRO
	jr .j1367\@ ; 12t, 2 bytes
.j1367\@:
	jr .j1368\@ ; 12t, 2 bytes
.j1368\@:
	jr .j1369\@ ; 12t, 2 bytes
.j1369\@:
	jr .j1370\@ ; 12t, 2 bytes
.j1370\@:
	jr .j1371\@ ; 12t, 2 bytes
.j1371\@:
	jr .j1372\@ ; 12t, 2 bytes
.j1372\@:
	jr .j1373\@ ; 12t, 2 bytes
.j1373\@:
	jr .j1374\@ ; 12t, 2 bytes
.j1374\@:
	jr .j1375\@ ; 12t, 2 bytes
.j1375\@:
	jr .j1376\@ ; 12t, 2 bytes
.j1376\@:
	jr .j1377\@ ; 12t, 2 bytes
.j1377\@:
	jr .j1378\@ ; 12t, 2 bytes
.j1378\@:
	jr .j1379\@ ; 12t, 2 bytes
.j1379\@:
	jr .j1380\@ ; 12t, 2 bytes
.j1380\@:
	jr .j1381\@ ; 12t, 2 bytes
.j1381\@:
	jr .j1382\@ ; 12t, 2 bytes
.j1382\@:
	ENDM

sleep_193 MACRO
	nop
	or 0
	or 0
	or 0
	jr .j1383\@ ; 12t, 2 bytes
.j1383\@:
	jr .j1384\@ ; 12t, 2 bytes
.j1384\@:
	jr .j1385\@ ; 12t, 2 bytes
.j1385\@:
	jr .j1386\@ ; 12t, 2 bytes
.j1386\@:
	jr .j1387\@ ; 12t, 2 bytes
.j1387\@:
	jr .j1388\@ ; 12t, 2 bytes
.j1388\@:
	jr .j1389\@ ; 12t, 2 bytes
.j1389\@:
	jr .j1390\@ ; 12t, 2 bytes
.j1390\@:
	jr .j1391\@ ; 12t, 2 bytes
.j1391\@:
	jr .j1392\@ ; 12t, 2 bytes
.j1392\@:
	jr .j1393\@ ; 12t, 2 bytes
.j1393\@:
	jr .j1394\@ ; 12t, 2 bytes
.j1394\@:
	jr .j1395\@ ; 12t, 2 bytes
.j1395\@:
	jr .j1396\@ ; 12t, 2 bytes
.j1396\@:
	ENDM

sleep_194 MACRO
	or 0
	or 0
	jr .j1397\@ ; 12t, 2 bytes
.j1397\@:
	jr .j1398\@ ; 12t, 2 bytes
.j1398\@:
	jr .j1399\@ ; 12t, 2 bytes
.j1399\@:
	jr .j1400\@ ; 12t, 2 bytes
.j1400\@:
	jr .j1401\@ ; 12t, 2 bytes
.j1401\@:
	jr .j1402\@ ; 12t, 2 bytes
.j1402\@:
	jr .j1403\@ ; 12t, 2 bytes
.j1403\@:
	jr .j1404\@ ; 12t, 2 bytes
.j1404\@:
	jr .j1405\@ ; 12t, 2 bytes
.j1405\@:
	jr .j1406\@ ; 12t, 2 bytes
.j1406\@:
	jr .j1407\@ ; 12t, 2 bytes
.j1407\@:
	jr .j1408\@ ; 12t, 2 bytes
.j1408\@:
	jr .j1409\@ ; 12t, 2 bytes
.j1409\@:
	jr .j1410\@ ; 12t, 2 bytes
.j1410\@:
	jr .j1411\@ ; 12t, 2 bytes
.j1411\@:
	ENDM

sleep_195 MACRO
	nop
	nop
	or 0
	jr .j1412\@ ; 12t, 2 bytes
.j1412\@:
	jr .j1413\@ ; 12t, 2 bytes
.j1413\@:
	jr .j1414\@ ; 12t, 2 bytes
.j1414\@:
	jr .j1415\@ ; 12t, 2 bytes
.j1415\@:
	jr .j1416\@ ; 12t, 2 bytes
.j1416\@:
	jr .j1417\@ ; 12t, 2 bytes
.j1417\@:
	jr .j1418\@ ; 12t, 2 bytes
.j1418\@:
	jr .j1419\@ ; 12t, 2 bytes
.j1419\@:
	jr .j1420\@ ; 12t, 2 bytes
.j1420\@:
	jr .j1421\@ ; 12t, 2 bytes
.j1421\@:
	jr .j1422\@ ; 12t, 2 bytes
.j1422\@:
	jr .j1423\@ ; 12t, 2 bytes
.j1423\@:
	jr .j1424\@ ; 12t, 2 bytes
.j1424\@:
	jr .j1425\@ ; 12t, 2 bytes
.j1425\@:
	jr .j1426\@ ; 12t, 2 bytes
.j1426\@:
	ENDM

sleep_196 MACRO
	nop
	jr .j1427\@ ; 12t, 2 bytes
.j1427\@:
	jr .j1428\@ ; 12t, 2 bytes
.j1428\@:
	jr .j1429\@ ; 12t, 2 bytes
.j1429\@:
	jr .j1430\@ ; 12t, 2 bytes
.j1430\@:
	jr .j1431\@ ; 12t, 2 bytes
.j1431\@:
	jr .j1432\@ ; 12t, 2 bytes
.j1432\@:
	jr .j1433\@ ; 12t, 2 bytes
.j1433\@:
	jr .j1434\@ ; 12t, 2 bytes
.j1434\@:
	jr .j1435\@ ; 12t, 2 bytes
.j1435\@:
	jr .j1436\@ ; 12t, 2 bytes
.j1436\@:
	jr .j1437\@ ; 12t, 2 bytes
.j1437\@:
	jr .j1438\@ ; 12t, 2 bytes
.j1438\@:
	jr .j1439\@ ; 12t, 2 bytes
.j1439\@:
	jr .j1440\@ ; 12t, 2 bytes
.j1440\@:
	jr .j1441\@ ; 12t, 2 bytes
.j1441\@:
	jr .j1442\@ ; 12t, 2 bytes
.j1442\@:
	ENDM

sleep_197 MACRO
	or 0
	jp .j1443\@ ; 10t, 3 bytes
.j1443\@:
	jr .j1444\@ ; 12t, 2 bytes
.j1444\@:
	jr .j1445\@ ; 12t, 2 bytes
.j1445\@:
	jr .j1446\@ ; 12t, 2 bytes
.j1446\@:
	jr .j1447\@ ; 12t, 2 bytes
.j1447\@:
	jr .j1448\@ ; 12t, 2 bytes
.j1448\@:
	jr .j1449\@ ; 12t, 2 bytes
.j1449\@:
	jr .j1450\@ ; 12t, 2 bytes
.j1450\@:
	jr .j1451\@ ; 12t, 2 bytes
.j1451\@:
	jr .j1452\@ ; 12t, 2 bytes
.j1452\@:
	jr .j1453\@ ; 12t, 2 bytes
.j1453\@:
	jr .j1454\@ ; 12t, 2 bytes
.j1454\@:
	jr .j1455\@ ; 12t, 2 bytes
.j1455\@:
	jr .j1456\@ ; 12t, 2 bytes
.j1456\@:
	jr .j1457\@ ; 12t, 2 bytes
.j1457\@:
	jr .j1458\@ ; 12t, 2 bytes
.j1458\@:
	ENDM

sleep_198 MACRO
	nop
	or 0
	or 0
	jr .j1459\@ ; 12t, 2 bytes
.j1459\@:
	jr .j1460\@ ; 12t, 2 bytes
.j1460\@:
	jr .j1461\@ ; 12t, 2 bytes
.j1461\@:
	jr .j1462\@ ; 12t, 2 bytes
.j1462\@:
	jr .j1463\@ ; 12t, 2 bytes
.j1463\@:
	jr .j1464\@ ; 12t, 2 bytes
.j1464\@:
	jr .j1465\@ ; 12t, 2 bytes
.j1465\@:
	jr .j1466\@ ; 12t, 2 bytes
.j1466\@:
	jr .j1467\@ ; 12t, 2 bytes
.j1467\@:
	jr .j1468\@ ; 12t, 2 bytes
.j1468\@:
	jr .j1469\@ ; 12t, 2 bytes
.j1469\@:
	jr .j1470\@ ; 12t, 2 bytes
.j1470\@:
	jr .j1471\@ ; 12t, 2 bytes
.j1471\@:
	jr .j1472\@ ; 12t, 2 bytes
.j1472\@:
	jr .j1473\@ ; 12t, 2 bytes
.j1473\@:
	ENDM

sleep_199 MACRO
	or 0
	jr .j1474\@ ; 12t, 2 bytes
.j1474\@:
	jr .j1475\@ ; 12t, 2 bytes
.j1475\@:
	jr .j1476\@ ; 12t, 2 bytes
.j1476\@:
	jr .j1477\@ ; 12t, 2 bytes
.j1477\@:
	jr .j1478\@ ; 12t, 2 bytes
.j1478\@:
	jr .j1479\@ ; 12t, 2 bytes
.j1479\@:
	jr .j1480\@ ; 12t, 2 bytes
.j1480\@:
	jr .j1481\@ ; 12t, 2 bytes
.j1481\@:
	jr .j1482\@ ; 12t, 2 bytes
.j1482\@:
	jr .j1483\@ ; 12t, 2 bytes
.j1483\@:
	jr .j1484\@ ; 12t, 2 bytes
.j1484\@:
	jr .j1485\@ ; 12t, 2 bytes
.j1485\@:
	jr .j1486\@ ; 12t, 2 bytes
.j1486\@:
	jr .j1487\@ ; 12t, 2 bytes
.j1487\@:
	jr .j1488\@ ; 12t, 2 bytes
.j1488\@:
	jr .j1489\@ ; 12t, 2 bytes
.j1489\@:
	ENDM

sleep_200 MACRO
	nop
	nop
	jr .j1490\@ ; 12t, 2 bytes
.j1490\@:
	jr .j1491\@ ; 12t, 2 bytes
.j1491\@:
	jr .j1492\@ ; 12t, 2 bytes
.j1492\@:
	jr .j1493\@ ; 12t, 2 bytes
.j1493\@:
	jr .j1494\@ ; 12t, 2 bytes
.j1494\@:
	jr .j1495\@ ; 12t, 2 bytes
.j1495\@:
	jr .j1496\@ ; 12t, 2 bytes
.j1496\@:
	jr .j1497\@ ; 12t, 2 bytes
.j1497\@:
	jr .j1498\@ ; 12t, 2 bytes
.j1498\@:
	jr .j1499\@ ; 12t, 2 bytes
.j1499\@:
	jr .j1500\@ ; 12t, 2 bytes
.j1500\@:
	jr .j1501\@ ; 12t, 2 bytes
.j1501\@:
	jr .j1502\@ ; 12t, 2 bytes
.j1502\@:
	jr .j1503\@ ; 12t, 2 bytes
.j1503\@:
	jr .j1504\@ ; 12t, 2 bytes
.j1504\@:
	jr .j1505\@ ; 12t, 2 bytes
.j1505\@:
	ENDM

sleep_201 MACRO
	or 0
	or 0
	or 0
	jr .j1506\@ ; 12t, 2 bytes
.j1506\@:
	jr .j1507\@ ; 12t, 2 bytes
.j1507\@:
	jr .j1508\@ ; 12t, 2 bytes
.j1508\@:
	jr .j1509\@ ; 12t, 2 bytes
.j1509\@:
	jr .j1510\@ ; 12t, 2 bytes
.j1510\@:
	jr .j1511\@ ; 12t, 2 bytes
.j1511\@:
	jr .j1512\@ ; 12t, 2 bytes
.j1512\@:
	jr .j1513\@ ; 12t, 2 bytes
.j1513\@:
	jr .j1514\@ ; 12t, 2 bytes
.j1514\@:
	jr .j1515\@ ; 12t, 2 bytes
.j1515\@:
	jr .j1516\@ ; 12t, 2 bytes
.j1516\@:
	jr .j1517\@ ; 12t, 2 bytes
.j1517\@:
	jr .j1518\@ ; 12t, 2 bytes
.j1518\@:
	jr .j1519\@ ; 12t, 2 bytes
.j1519\@:
	jr .j1520\@ ; 12t, 2 bytes
.j1520\@:
	ENDM

sleep_202 MACRO
	jp .j1521\@ ; 10t, 3 bytes
.j1521\@:
	jr .j1522\@ ; 12t, 2 bytes
.j1522\@:
	jr .j1523\@ ; 12t, 2 bytes
.j1523\@:
	jr .j1524\@ ; 12t, 2 bytes
.j1524\@:
	jr .j1525\@ ; 12t, 2 bytes
.j1525\@:
	jr .j1526\@ ; 12t, 2 bytes
.j1526\@:
	jr .j1527\@ ; 12t, 2 bytes
.j1527\@:
	jr .j1528\@ ; 12t, 2 bytes
.j1528\@:
	jr .j1529\@ ; 12t, 2 bytes
.j1529\@:
	jr .j1530\@ ; 12t, 2 bytes
.j1530\@:
	jr .j1531\@ ; 12t, 2 bytes
.j1531\@:
	jr .j1532\@ ; 12t, 2 bytes
.j1532\@:
	jr .j1533\@ ; 12t, 2 bytes
.j1533\@:
	jr .j1534\@ ; 12t, 2 bytes
.j1534\@:
	jr .j1535\@ ; 12t, 2 bytes
.j1535\@:
	jr .j1536\@ ; 12t, 2 bytes
.j1536\@:
	jr .j1537\@ ; 12t, 2 bytes
.j1537\@:
	ENDM

sleep_203 MACRO
	nop
	or 0
	jr .j1538\@ ; 12t, 2 bytes
.j1538\@:
	jr .j1539\@ ; 12t, 2 bytes
.j1539\@:
	jr .j1540\@ ; 12t, 2 bytes
.j1540\@:
	jr .j1541\@ ; 12t, 2 bytes
.j1541\@:
	jr .j1542\@ ; 12t, 2 bytes
.j1542\@:
	jr .j1543\@ ; 12t, 2 bytes
.j1543\@:
	jr .j1544\@ ; 12t, 2 bytes
.j1544\@:
	jr .j1545\@ ; 12t, 2 bytes
.j1545\@:
	jr .j1546\@ ; 12t, 2 bytes
.j1546\@:
	jr .j1547\@ ; 12t, 2 bytes
.j1547\@:
	jr .j1548\@ ; 12t, 2 bytes
.j1548\@:
	jr .j1549\@ ; 12t, 2 bytes
.j1549\@:
	jr .j1550\@ ; 12t, 2 bytes
.j1550\@:
	jr .j1551\@ ; 12t, 2 bytes
.j1551\@:
	jr .j1552\@ ; 12t, 2 bytes
.j1552\@:
	jr .j1553\@ ; 12t, 2 bytes
.j1553\@:
	ENDM

sleep_204 MACRO
	jr .j1554\@ ; 12t, 2 bytes
.j1554\@:
	jr .j1555\@ ; 12t, 2 bytes
.j1555\@:
	jr .j1556\@ ; 12t, 2 bytes
.j1556\@:
	jr .j1557\@ ; 12t, 2 bytes
.j1557\@:
	jr .j1558\@ ; 12t, 2 bytes
.j1558\@:
	jr .j1559\@ ; 12t, 2 bytes
.j1559\@:
	jr .j1560\@ ; 12t, 2 bytes
.j1560\@:
	jr .j1561\@ ; 12t, 2 bytes
.j1561\@:
	jr .j1562\@ ; 12t, 2 bytes
.j1562\@:
	jr .j1563\@ ; 12t, 2 bytes
.j1563\@:
	jr .j1564\@ ; 12t, 2 bytes
.j1564\@:
	jr .j1565\@ ; 12t, 2 bytes
.j1565\@:
	jr .j1566\@ ; 12t, 2 bytes
.j1566\@:
	jr .j1567\@ ; 12t, 2 bytes
.j1567\@:
	jr .j1568\@ ; 12t, 2 bytes
.j1568\@:
	jr .j1569\@ ; 12t, 2 bytes
.j1569\@:
	jr .j1570\@ ; 12t, 2 bytes
.j1570\@:
	ENDM

sleep_205 MACRO
	nop
	or 0
	or 0
	or 0
	jr .j1571\@ ; 12t, 2 bytes
.j1571\@:
	jr .j1572\@ ; 12t, 2 bytes
.j1572\@:
	jr .j1573\@ ; 12t, 2 bytes
.j1573\@:
	jr .j1574\@ ; 12t, 2 bytes
.j1574\@:
	jr .j1575\@ ; 12t, 2 bytes
.j1575\@:
	jr .j1576\@ ; 12t, 2 bytes
.j1576\@:
	jr .j1577\@ ; 12t, 2 bytes
.j1577\@:
	jr .j1578\@ ; 12t, 2 bytes
.j1578\@:
	jr .j1579\@ ; 12t, 2 bytes
.j1579\@:
	jr .j1580\@ ; 12t, 2 bytes
.j1580\@:
	jr .j1581\@ ; 12t, 2 bytes
.j1581\@:
	jr .j1582\@ ; 12t, 2 bytes
.j1582\@:
	jr .j1583\@ ; 12t, 2 bytes
.j1583\@:
	jr .j1584\@ ; 12t, 2 bytes
.j1584\@:
	jr .j1585\@ ; 12t, 2 bytes
.j1585\@:
	ENDM

sleep_206 MACRO
	or 0
	or 0
	jr .j1586\@ ; 12t, 2 bytes
.j1586\@:
	jr .j1587\@ ; 12t, 2 bytes
.j1587\@:
	jr .j1588\@ ; 12t, 2 bytes
.j1588\@:
	jr .j1589\@ ; 12t, 2 bytes
.j1589\@:
	jr .j1590\@ ; 12t, 2 bytes
.j1590\@:
	jr .j1591\@ ; 12t, 2 bytes
.j1591\@:
	jr .j1592\@ ; 12t, 2 bytes
.j1592\@:
	jr .j1593\@ ; 12t, 2 bytes
.j1593\@:
	jr .j1594\@ ; 12t, 2 bytes
.j1594\@:
	jr .j1595\@ ; 12t, 2 bytes
.j1595\@:
	jr .j1596\@ ; 12t, 2 bytes
.j1596\@:
	jr .j1597\@ ; 12t, 2 bytes
.j1597\@:
	jr .j1598\@ ; 12t, 2 bytes
.j1598\@:
	jr .j1599\@ ; 12t, 2 bytes
.j1599\@:
	jr .j1600\@ ; 12t, 2 bytes
.j1600\@:
	jr .j1601\@ ; 12t, 2 bytes
.j1601\@:
	ENDM

sleep_207 MACRO
	nop
	nop
	or 0
	jr .j1602\@ ; 12t, 2 bytes
.j1602\@:
	jr .j1603\@ ; 12t, 2 bytes
.j1603\@:
	jr .j1604\@ ; 12t, 2 bytes
.j1604\@:
	jr .j1605\@ ; 12t, 2 bytes
.j1605\@:
	jr .j1606\@ ; 12t, 2 bytes
.j1606\@:
	jr .j1607\@ ; 12t, 2 bytes
.j1607\@:
	jr .j1608\@ ; 12t, 2 bytes
.j1608\@:
	jr .j1609\@ ; 12t, 2 bytes
.j1609\@:
	jr .j1610\@ ; 12t, 2 bytes
.j1610\@:
	jr .j1611\@ ; 12t, 2 bytes
.j1611\@:
	jr .j1612\@ ; 12t, 2 bytes
.j1612\@:
	jr .j1613\@ ; 12t, 2 bytes
.j1613\@:
	jr .j1614\@ ; 12t, 2 bytes
.j1614\@:
	jr .j1615\@ ; 12t, 2 bytes
.j1615\@:
	jr .j1616\@ ; 12t, 2 bytes
.j1616\@:
	jr .j1617\@ ; 12t, 2 bytes
.j1617\@:
	ENDM

sleep_208 MACRO
	nop
	jr .j1618\@ ; 12t, 2 bytes
.j1618\@:
	jr .j1619\@ ; 12t, 2 bytes
.j1619\@:
	jr .j1620\@ ; 12t, 2 bytes
.j1620\@:
	jr .j1621\@ ; 12t, 2 bytes
.j1621\@:
	jr .j1622\@ ; 12t, 2 bytes
.j1622\@:
	jr .j1623\@ ; 12t, 2 bytes
.j1623\@:
	jr .j1624\@ ; 12t, 2 bytes
.j1624\@:
	jr .j1625\@ ; 12t, 2 bytes
.j1625\@:
	jr .j1626\@ ; 12t, 2 bytes
.j1626\@:
	jr .j1627\@ ; 12t, 2 bytes
.j1627\@:
	jr .j1628\@ ; 12t, 2 bytes
.j1628\@:
	jr .j1629\@ ; 12t, 2 bytes
.j1629\@:
	jr .j1630\@ ; 12t, 2 bytes
.j1630\@:
	jr .j1631\@ ; 12t, 2 bytes
.j1631\@:
	jr .j1632\@ ; 12t, 2 bytes
.j1632\@:
	jr .j1633\@ ; 12t, 2 bytes
.j1633\@:
	jr .j1634\@ ; 12t, 2 bytes
.j1634\@:
	ENDM

sleep_209 MACRO
	or 0
	jp .j1635\@ ; 10t, 3 bytes
.j1635\@:
	jr .j1636\@ ; 12t, 2 bytes
.j1636\@:
	jr .j1637\@ ; 12t, 2 bytes
.j1637\@:
	jr .j1638\@ ; 12t, 2 bytes
.j1638\@:
	jr .j1639\@ ; 12t, 2 bytes
.j1639\@:
	jr .j1640\@ ; 12t, 2 bytes
.j1640\@:
	jr .j1641\@ ; 12t, 2 bytes
.j1641\@:
	jr .j1642\@ ; 12t, 2 bytes
.j1642\@:
	jr .j1643\@ ; 12t, 2 bytes
.j1643\@:
	jr .j1644\@ ; 12t, 2 bytes
.j1644\@:
	jr .j1645\@ ; 12t, 2 bytes
.j1645\@:
	jr .j1646\@ ; 12t, 2 bytes
.j1646\@:
	jr .j1647\@ ; 12t, 2 bytes
.j1647\@:
	jr .j1648\@ ; 12t, 2 bytes
.j1648\@:
	jr .j1649\@ ; 12t, 2 bytes
.j1649\@:
	jr .j1650\@ ; 12t, 2 bytes
.j1650\@:
	jr .j1651\@ ; 12t, 2 bytes
.j1651\@:
	ENDM

sleep_210 MACRO
	nop
	or 0
	or 0
	jr .j1652\@ ; 12t, 2 bytes
.j1652\@:
	jr .j1653\@ ; 12t, 2 bytes
.j1653\@:
	jr .j1654\@ ; 12t, 2 bytes
.j1654\@:
	jr .j1655\@ ; 12t, 2 bytes
.j1655\@:
	jr .j1656\@ ; 12t, 2 bytes
.j1656\@:
	jr .j1657\@ ; 12t, 2 bytes
.j1657\@:
	jr .j1658\@ ; 12t, 2 bytes
.j1658\@:
	jr .j1659\@ ; 12t, 2 bytes
.j1659\@:
	jr .j1660\@ ; 12t, 2 bytes
.j1660\@:
	jr .j1661\@ ; 12t, 2 bytes
.j1661\@:
	jr .j1662\@ ; 12t, 2 bytes
.j1662\@:
	jr .j1663\@ ; 12t, 2 bytes
.j1663\@:
	jr .j1664\@ ; 12t, 2 bytes
.j1664\@:
	jr .j1665\@ ; 12t, 2 bytes
.j1665\@:
	jr .j1666\@ ; 12t, 2 bytes
.j1666\@:
	jr .j1667\@ ; 12t, 2 bytes
.j1667\@:
	ENDM

sleep_211 MACRO
	or 0
	jr .j1668\@ ; 12t, 2 bytes
.j1668\@:
	jr .j1669\@ ; 12t, 2 bytes
.j1669\@:
	jr .j1670\@ ; 12t, 2 bytes
.j1670\@:
	jr .j1671\@ ; 12t, 2 bytes
.j1671\@:
	jr .j1672\@ ; 12t, 2 bytes
.j1672\@:
	jr .j1673\@ ; 12t, 2 bytes
.j1673\@:
	jr .j1674\@ ; 12t, 2 bytes
.j1674\@:
	jr .j1675\@ ; 12t, 2 bytes
.j1675\@:
	jr .j1676\@ ; 12t, 2 bytes
.j1676\@:
	jr .j1677\@ ; 12t, 2 bytes
.j1677\@:
	jr .j1678\@ ; 12t, 2 bytes
.j1678\@:
	jr .j1679\@ ; 12t, 2 bytes
.j1679\@:
	jr .j1680\@ ; 12t, 2 bytes
.j1680\@:
	jr .j1681\@ ; 12t, 2 bytes
.j1681\@:
	jr .j1682\@ ; 12t, 2 bytes
.j1682\@:
	jr .j1683\@ ; 12t, 2 bytes
.j1683\@:
	jr .j1684\@ ; 12t, 2 bytes
.j1684\@:
	ENDM

sleep_212 MACRO
	nop
	nop
	jr .j1685\@ ; 12t, 2 bytes
.j1685\@:
	jr .j1686\@ ; 12t, 2 bytes
.j1686\@:
	jr .j1687\@ ; 12t, 2 bytes
.j1687\@:
	jr .j1688\@ ; 12t, 2 bytes
.j1688\@:
	jr .j1689\@ ; 12t, 2 bytes
.j1689\@:
	jr .j1690\@ ; 12t, 2 bytes
.j1690\@:
	jr .j1691\@ ; 12t, 2 bytes
.j1691\@:
	jr .j1692\@ ; 12t, 2 bytes
.j1692\@:
	jr .j1693\@ ; 12t, 2 bytes
.j1693\@:
	jr .j1694\@ ; 12t, 2 bytes
.j1694\@:
	jr .j1695\@ ; 12t, 2 bytes
.j1695\@:
	jr .j1696\@ ; 12t, 2 bytes
.j1696\@:
	jr .j1697\@ ; 12t, 2 bytes
.j1697\@:
	jr .j1698\@ ; 12t, 2 bytes
.j1698\@:
	jr .j1699\@ ; 12t, 2 bytes
.j1699\@:
	jr .j1700\@ ; 12t, 2 bytes
.j1700\@:
	jr .j1701\@ ; 12t, 2 bytes
.j1701\@:
	ENDM

sleep_213 MACRO
	or 0
	or 0
	or 0
	jr .j1702\@ ; 12t, 2 bytes
.j1702\@:
	jr .j1703\@ ; 12t, 2 bytes
.j1703\@:
	jr .j1704\@ ; 12t, 2 bytes
.j1704\@:
	jr .j1705\@ ; 12t, 2 bytes
.j1705\@:
	jr .j1706\@ ; 12t, 2 bytes
.j1706\@:
	jr .j1707\@ ; 12t, 2 bytes
.j1707\@:
	jr .j1708\@ ; 12t, 2 bytes
.j1708\@:
	jr .j1709\@ ; 12t, 2 bytes
.j1709\@:
	jr .j1710\@ ; 12t, 2 bytes
.j1710\@:
	jr .j1711\@ ; 12t, 2 bytes
.j1711\@:
	jr .j1712\@ ; 12t, 2 bytes
.j1712\@:
	jr .j1713\@ ; 12t, 2 bytes
.j1713\@:
	jr .j1714\@ ; 12t, 2 bytes
.j1714\@:
	jr .j1715\@ ; 12t, 2 bytes
.j1715\@:
	jr .j1716\@ ; 12t, 2 bytes
.j1716\@:
	jr .j1717\@ ; 12t, 2 bytes
.j1717\@:
	ENDM

sleep_214 MACRO
	jp .j1718\@ ; 10t, 3 bytes
.j1718\@:
	jr .j1719\@ ; 12t, 2 bytes
.j1719\@:
	jr .j1720\@ ; 12t, 2 bytes
.j1720\@:
	jr .j1721\@ ; 12t, 2 bytes
.j1721\@:
	jr .j1722\@ ; 12t, 2 bytes
.j1722\@:
	jr .j1723\@ ; 12t, 2 bytes
.j1723\@:
	jr .j1724\@ ; 12t, 2 bytes
.j1724\@:
	jr .j1725\@ ; 12t, 2 bytes
.j1725\@:
	jr .j1726\@ ; 12t, 2 bytes
.j1726\@:
	jr .j1727\@ ; 12t, 2 bytes
.j1727\@:
	jr .j1728\@ ; 12t, 2 bytes
.j1728\@:
	jr .j1729\@ ; 12t, 2 bytes
.j1729\@:
	jr .j1730\@ ; 12t, 2 bytes
.j1730\@:
	jr .j1731\@ ; 12t, 2 bytes
.j1731\@:
	jr .j1732\@ ; 12t, 2 bytes
.j1732\@:
	jr .j1733\@ ; 12t, 2 bytes
.j1733\@:
	jr .j1734\@ ; 12t, 2 bytes
.j1734\@:
	jr .j1735\@ ; 12t, 2 bytes
.j1735\@:
	ENDM

sleep_215 MACRO
	nop
	or 0
	jr .j1736\@ ; 12t, 2 bytes
.j1736\@:
	jr .j1737\@ ; 12t, 2 bytes
.j1737\@:
	jr .j1738\@ ; 12t, 2 bytes
.j1738\@:
	jr .j1739\@ ; 12t, 2 bytes
.j1739\@:
	jr .j1740\@ ; 12t, 2 bytes
.j1740\@:
	jr .j1741\@ ; 12t, 2 bytes
.j1741\@:
	jr .j1742\@ ; 12t, 2 bytes
.j1742\@:
	jr .j1743\@ ; 12t, 2 bytes
.j1743\@:
	jr .j1744\@ ; 12t, 2 bytes
.j1744\@:
	jr .j1745\@ ; 12t, 2 bytes
.j1745\@:
	jr .j1746\@ ; 12t, 2 bytes
.j1746\@:
	jr .j1747\@ ; 12t, 2 bytes
.j1747\@:
	jr .j1748\@ ; 12t, 2 bytes
.j1748\@:
	jr .j1749\@ ; 12t, 2 bytes
.j1749\@:
	jr .j1750\@ ; 12t, 2 bytes
.j1750\@:
	jr .j1751\@ ; 12t, 2 bytes
.j1751\@:
	jr .j1752\@ ; 12t, 2 bytes
.j1752\@:
	ENDM

sleep_216 MACRO
	jr .j1753\@ ; 12t, 2 bytes
.j1753\@:
	jr .j1754\@ ; 12t, 2 bytes
.j1754\@:
	jr .j1755\@ ; 12t, 2 bytes
.j1755\@:
	jr .j1756\@ ; 12t, 2 bytes
.j1756\@:
	jr .j1757\@ ; 12t, 2 bytes
.j1757\@:
	jr .j1758\@ ; 12t, 2 bytes
.j1758\@:
	jr .j1759\@ ; 12t, 2 bytes
.j1759\@:
	jr .j1760\@ ; 12t, 2 bytes
.j1760\@:
	jr .j1761\@ ; 12t, 2 bytes
.j1761\@:
	jr .j1762\@ ; 12t, 2 bytes
.j1762\@:
	jr .j1763\@ ; 12t, 2 bytes
.j1763\@:
	jr .j1764\@ ; 12t, 2 bytes
.j1764\@:
	jr .j1765\@ ; 12t, 2 bytes
.j1765\@:
	jr .j1766\@ ; 12t, 2 bytes
.j1766\@:
	jr .j1767\@ ; 12t, 2 bytes
.j1767\@:
	jr .j1768\@ ; 12t, 2 bytes
.j1768\@:
	jr .j1769\@ ; 12t, 2 bytes
.j1769\@:
	jr .j1770\@ ; 12t, 2 bytes
.j1770\@:
	ENDM

sleep_217 MACRO
	nop
	or 0
	or 0
	or 0
	jr .j1771\@ ; 12t, 2 bytes
.j1771\@:
	jr .j1772\@ ; 12t, 2 bytes
.j1772\@:
	jr .j1773\@ ; 12t, 2 bytes
.j1773\@:
	jr .j1774\@ ; 12t, 2 bytes
.j1774\@:
	jr .j1775\@ ; 12t, 2 bytes
.j1775\@:
	jr .j1776\@ ; 12t, 2 bytes
.j1776\@:
	jr .j1777\@ ; 12t, 2 bytes
.j1777\@:
	jr .j1778\@ ; 12t, 2 bytes
.j1778\@:
	jr .j1779\@ ; 12t, 2 bytes
.j1779\@:
	jr .j1780\@ ; 12t, 2 bytes
.j1780\@:
	jr .j1781\@ ; 12t, 2 bytes
.j1781\@:
	jr .j1782\@ ; 12t, 2 bytes
.j1782\@:
	jr .j1783\@ ; 12t, 2 bytes
.j1783\@:
	jr .j1784\@ ; 12t, 2 bytes
.j1784\@:
	jr .j1785\@ ; 12t, 2 bytes
.j1785\@:
	jr .j1786\@ ; 12t, 2 bytes
.j1786\@:
	ENDM

sleep_218 MACRO
	or 0
	or 0
	jr .j1787\@ ; 12t, 2 bytes
.j1787\@:
	jr .j1788\@ ; 12t, 2 bytes
.j1788\@:
	jr .j1789\@ ; 12t, 2 bytes
.j1789\@:
	jr .j1790\@ ; 12t, 2 bytes
.j1790\@:
	jr .j1791\@ ; 12t, 2 bytes
.j1791\@:
	jr .j1792\@ ; 12t, 2 bytes
.j1792\@:
	jr .j1793\@ ; 12t, 2 bytes
.j1793\@:
	jr .j1794\@ ; 12t, 2 bytes
.j1794\@:
	jr .j1795\@ ; 12t, 2 bytes
.j1795\@:
	jr .j1796\@ ; 12t, 2 bytes
.j1796\@:
	jr .j1797\@ ; 12t, 2 bytes
.j1797\@:
	jr .j1798\@ ; 12t, 2 bytes
.j1798\@:
	jr .j1799\@ ; 12t, 2 bytes
.j1799\@:
	jr .j1800\@ ; 12t, 2 bytes
.j1800\@:
	jr .j1801\@ ; 12t, 2 bytes
.j1801\@:
	jr .j1802\@ ; 12t, 2 bytes
.j1802\@:
	jr .j1803\@ ; 12t, 2 bytes
.j1803\@:
	ENDM

sleep_219 MACRO
	nop
	nop
	or 0
	jr .j1804\@ ; 12t, 2 bytes
.j1804\@:
	jr .j1805\@ ; 12t, 2 bytes
.j1805\@:
	jr .j1806\@ ; 12t, 2 bytes
.j1806\@:
	jr .j1807\@ ; 12t, 2 bytes
.j1807\@:
	jr .j1808\@ ; 12t, 2 bytes
.j1808\@:
	jr .j1809\@ ; 12t, 2 bytes
.j1809\@:
	jr .j1810\@ ; 12t, 2 bytes
.j1810\@:
	jr .j1811\@ ; 12t, 2 bytes
.j1811\@:
	jr .j1812\@ ; 12t, 2 bytes
.j1812\@:
	jr .j1813\@ ; 12t, 2 bytes
.j1813\@:
	jr .j1814\@ ; 12t, 2 bytes
.j1814\@:
	jr .j1815\@ ; 12t, 2 bytes
.j1815\@:
	jr .j1816\@ ; 12t, 2 bytes
.j1816\@:
	jr .j1817\@ ; 12t, 2 bytes
.j1817\@:
	jr .j1818\@ ; 12t, 2 bytes
.j1818\@:
	jr .j1819\@ ; 12t, 2 bytes
.j1819\@:
	jr .j1820\@ ; 12t, 2 bytes
.j1820\@:
	ENDM

sleep_220 MACRO
	nop
	jr .j1821\@ ; 12t, 2 bytes
.j1821\@:
	jr .j1822\@ ; 12t, 2 bytes
.j1822\@:
	jr .j1823\@ ; 12t, 2 bytes
.j1823\@:
	jr .j1824\@ ; 12t, 2 bytes
.j1824\@:
	jr .j1825\@ ; 12t, 2 bytes
.j1825\@:
	jr .j1826\@ ; 12t, 2 bytes
.j1826\@:
	jr .j1827\@ ; 12t, 2 bytes
.j1827\@:
	jr .j1828\@ ; 12t, 2 bytes
.j1828\@:
	jr .j1829\@ ; 12t, 2 bytes
.j1829\@:
	jr .j1830\@ ; 12t, 2 bytes
.j1830\@:
	jr .j1831\@ ; 12t, 2 bytes
.j1831\@:
	jr .j1832\@ ; 12t, 2 bytes
.j1832\@:
	jr .j1833\@ ; 12t, 2 bytes
.j1833\@:
	jr .j1834\@ ; 12t, 2 bytes
.j1834\@:
	jr .j1835\@ ; 12t, 2 bytes
.j1835\@:
	jr .j1836\@ ; 12t, 2 bytes
.j1836\@:
	jr .j1837\@ ; 12t, 2 bytes
.j1837\@:
	jr .j1838\@ ; 12t, 2 bytes
.j1838\@:
	ENDM

sleep_221 MACRO
	or 0
	jp .j1839\@ ; 10t, 3 bytes
.j1839\@:
	jr .j1840\@ ; 12t, 2 bytes
.j1840\@:
	jr .j1841\@ ; 12t, 2 bytes
.j1841\@:
	jr .j1842\@ ; 12t, 2 bytes
.j1842\@:
	jr .j1843\@ ; 12t, 2 bytes
.j1843\@:
	jr .j1844\@ ; 12t, 2 bytes
.j1844\@:
	jr .j1845\@ ; 12t, 2 bytes
.j1845\@:
	jr .j1846\@ ; 12t, 2 bytes
.j1846\@:
	jr .j1847\@ ; 12t, 2 bytes
.j1847\@:
	jr .j1848\@ ; 12t, 2 bytes
.j1848\@:
	jr .j1849\@ ; 12t, 2 bytes
.j1849\@:
	jr .j1850\@ ; 12t, 2 bytes
.j1850\@:
	jr .j1851\@ ; 12t, 2 bytes
.j1851\@:
	jr .j1852\@ ; 12t, 2 bytes
.j1852\@:
	jr .j1853\@ ; 12t, 2 bytes
.j1853\@:
	jr .j1854\@ ; 12t, 2 bytes
.j1854\@:
	jr .j1855\@ ; 12t, 2 bytes
.j1855\@:
	jr .j1856\@ ; 12t, 2 bytes
.j1856\@:
	ENDM

sleep_222 MACRO
	nop
	or 0
	or 0
	jr .j1857\@ ; 12t, 2 bytes
.j1857\@:
	jr .j1858\@ ; 12t, 2 bytes
.j1858\@:
	jr .j1859\@ ; 12t, 2 bytes
.j1859\@:
	jr .j1860\@ ; 12t, 2 bytes
.j1860\@:
	jr .j1861\@ ; 12t, 2 bytes
.j1861\@:
	jr .j1862\@ ; 12t, 2 bytes
.j1862\@:
	jr .j1863\@ ; 12t, 2 bytes
.j1863\@:
	jr .j1864\@ ; 12t, 2 bytes
.j1864\@:
	jr .j1865\@ ; 12t, 2 bytes
.j1865\@:
	jr .j1866\@ ; 12t, 2 bytes
.j1866\@:
	jr .j1867\@ ; 12t, 2 bytes
.j1867\@:
	jr .j1868\@ ; 12t, 2 bytes
.j1868\@:
	jr .j1869\@ ; 12t, 2 bytes
.j1869\@:
	jr .j1870\@ ; 12t, 2 bytes
.j1870\@:
	jr .j1871\@ ; 12t, 2 bytes
.j1871\@:
	jr .j1872\@ ; 12t, 2 bytes
.j1872\@:
	jr .j1873\@ ; 12t, 2 bytes
.j1873\@:
	ENDM

sleep_223 MACRO
	or 0
	jr .j1874\@ ; 12t, 2 bytes
.j1874\@:
	jr .j1875\@ ; 12t, 2 bytes
.j1875\@:
	jr .j1876\@ ; 12t, 2 bytes
.j1876\@:
	jr .j1877\@ ; 12t, 2 bytes
.j1877\@:
	jr .j1878\@ ; 12t, 2 bytes
.j1878\@:
	jr .j1879\@ ; 12t, 2 bytes
.j1879\@:
	jr .j1880\@ ; 12t, 2 bytes
.j1880\@:
	jr .j1881\@ ; 12t, 2 bytes
.j1881\@:
	jr .j1882\@ ; 12t, 2 bytes
.j1882\@:
	jr .j1883\@ ; 12t, 2 bytes
.j1883\@:
	jr .j1884\@ ; 12t, 2 bytes
.j1884\@:
	jr .j1885\@ ; 12t, 2 bytes
.j1885\@:
	jr .j1886\@ ; 12t, 2 bytes
.j1886\@:
	jr .j1887\@ ; 12t, 2 bytes
.j1887\@:
	jr .j1888\@ ; 12t, 2 bytes
.j1888\@:
	jr .j1889\@ ; 12t, 2 bytes
.j1889\@:
	jr .j1890\@ ; 12t, 2 bytes
.j1890\@:
	jr .j1891\@ ; 12t, 2 bytes
.j1891\@:
	ENDM

sleep_224 MACRO
	nop
	nop
	jr .j1892\@ ; 12t, 2 bytes
.j1892\@:
	jr .j1893\@ ; 12t, 2 bytes
.j1893\@:
	jr .j1894\@ ; 12t, 2 bytes
.j1894\@:
	jr .j1895\@ ; 12t, 2 bytes
.j1895\@:
	jr .j1896\@ ; 12t, 2 bytes
.j1896\@:
	jr .j1897\@ ; 12t, 2 bytes
.j1897\@:
	jr .j1898\@ ; 12t, 2 bytes
.j1898\@:
	jr .j1899\@ ; 12t, 2 bytes
.j1899\@:
	jr .j1900\@ ; 12t, 2 bytes
.j1900\@:
	jr .j1901\@ ; 12t, 2 bytes
.j1901\@:
	jr .j1902\@ ; 12t, 2 bytes
.j1902\@:
	jr .j1903\@ ; 12t, 2 bytes
.j1903\@:
	jr .j1904\@ ; 12t, 2 bytes
.j1904\@:
	jr .j1905\@ ; 12t, 2 bytes
.j1905\@:
	jr .j1906\@ ; 12t, 2 bytes
.j1906\@:
	jr .j1907\@ ; 12t, 2 bytes
.j1907\@:
	jr .j1908\@ ; 12t, 2 bytes
.j1908\@:
	jr .j1909\@ ; 12t, 2 bytes
.j1909\@:
	ENDM

sleep_225 MACRO
	or 0
	or 0
	or 0
	jr .j1910\@ ; 12t, 2 bytes
.j1910\@:
	jr .j1911\@ ; 12t, 2 bytes
.j1911\@:
	jr .j1912\@ ; 12t, 2 bytes
.j1912\@:
	jr .j1913\@ ; 12t, 2 bytes
.j1913\@:
	jr .j1914\@ ; 12t, 2 bytes
.j1914\@:
	jr .j1915\@ ; 12t, 2 bytes
.j1915\@:
	jr .j1916\@ ; 12t, 2 bytes
.j1916\@:
	jr .j1917\@ ; 12t, 2 bytes
.j1917\@:
	jr .j1918\@ ; 12t, 2 bytes
.j1918\@:
	jr .j1919\@ ; 12t, 2 bytes
.j1919\@:
	jr .j1920\@ ; 12t, 2 bytes
.j1920\@:
	jr .j1921\@ ; 12t, 2 bytes
.j1921\@:
	jr .j1922\@ ; 12t, 2 bytes
.j1922\@:
	jr .j1923\@ ; 12t, 2 bytes
.j1923\@:
	jr .j1924\@ ; 12t, 2 bytes
.j1924\@:
	jr .j1925\@ ; 12t, 2 bytes
.j1925\@:
	jr .j1926\@ ; 12t, 2 bytes
.j1926\@:
	ENDM

sleep_226 MACRO
	jp .j1927\@ ; 10t, 3 bytes
.j1927\@:
	jr .j1928\@ ; 12t, 2 bytes
.j1928\@:
	jr .j1929\@ ; 12t, 2 bytes
.j1929\@:
	jr .j1930\@ ; 12t, 2 bytes
.j1930\@:
	jr .j1931\@ ; 12t, 2 bytes
.j1931\@:
	jr .j1932\@ ; 12t, 2 bytes
.j1932\@:
	jr .j1933\@ ; 12t, 2 bytes
.j1933\@:
	jr .j1934\@ ; 12t, 2 bytes
.j1934\@:
	jr .j1935\@ ; 12t, 2 bytes
.j1935\@:
	jr .j1936\@ ; 12t, 2 bytes
.j1936\@:
	jr .j1937\@ ; 12t, 2 bytes
.j1937\@:
	jr .j1938\@ ; 12t, 2 bytes
.j1938\@:
	jr .j1939\@ ; 12t, 2 bytes
.j1939\@:
	jr .j1940\@ ; 12t, 2 bytes
.j1940\@:
	jr .j1941\@ ; 12t, 2 bytes
.j1941\@:
	jr .j1942\@ ; 12t, 2 bytes
.j1942\@:
	jr .j1943\@ ; 12t, 2 bytes
.j1943\@:
	jr .j1944\@ ; 12t, 2 bytes
.j1944\@:
	jr .j1945\@ ; 12t, 2 bytes
.j1945\@:
	ENDM

sleep_227 MACRO
	nop
	or 0
	jr .j1946\@ ; 12t, 2 bytes
.j1946\@:
	jr .j1947\@ ; 12t, 2 bytes
.j1947\@:
	jr .j1948\@ ; 12t, 2 bytes
.j1948\@:
	jr .j1949\@ ; 12t, 2 bytes
.j1949\@:
	jr .j1950\@ ; 12t, 2 bytes
.j1950\@:
	jr .j1951\@ ; 12t, 2 bytes
.j1951\@:
	jr .j1952\@ ; 12t, 2 bytes
.j1952\@:
	jr .j1953\@ ; 12t, 2 bytes
.j1953\@:
	jr .j1954\@ ; 12t, 2 bytes
.j1954\@:
	jr .j1955\@ ; 12t, 2 bytes
.j1955\@:
	jr .j1956\@ ; 12t, 2 bytes
.j1956\@:
	jr .j1957\@ ; 12t, 2 bytes
.j1957\@:
	jr .j1958\@ ; 12t, 2 bytes
.j1958\@:
	jr .j1959\@ ; 12t, 2 bytes
.j1959\@:
	jr .j1960\@ ; 12t, 2 bytes
.j1960\@:
	jr .j1961\@ ; 12t, 2 bytes
.j1961\@:
	jr .j1962\@ ; 12t, 2 bytes
.j1962\@:
	jr .j1963\@ ; 12t, 2 bytes
.j1963\@:
	ENDM

sleep_228 MACRO
	jr .j1964\@ ; 12t, 2 bytes
.j1964\@:
	jr .j1965\@ ; 12t, 2 bytes
.j1965\@:
	jr .j1966\@ ; 12t, 2 bytes
.j1966\@:
	jr .j1967\@ ; 12t, 2 bytes
.j1967\@:
	jr .j1968\@ ; 12t, 2 bytes
.j1968\@:
	jr .j1969\@ ; 12t, 2 bytes
.j1969\@:
	jr .j1970\@ ; 12t, 2 bytes
.j1970\@:
	jr .j1971\@ ; 12t, 2 bytes
.j1971\@:
	jr .j1972\@ ; 12t, 2 bytes
.j1972\@:
	jr .j1973\@ ; 12t, 2 bytes
.j1973\@:
	jr .j1974\@ ; 12t, 2 bytes
.j1974\@:
	jr .j1975\@ ; 12t, 2 bytes
.j1975\@:
	jr .j1976\@ ; 12t, 2 bytes
.j1976\@:
	jr .j1977\@ ; 12t, 2 bytes
.j1977\@:
	jr .j1978\@ ; 12t, 2 bytes
.j1978\@:
	jr .j1979\@ ; 12t, 2 bytes
.j1979\@:
	jr .j1980\@ ; 12t, 2 bytes
.j1980\@:
	jr .j1981\@ ; 12t, 2 bytes
.j1981\@:
	jr .j1982\@ ; 12t, 2 bytes
.j1982\@:
	ENDM

sleep_229 MACRO
	nop
	or 0
	or 0
	or 0
	jr .j1983\@ ; 12t, 2 bytes
.j1983\@:
	jr .j1984\@ ; 12t, 2 bytes
.j1984\@:
	jr .j1985\@ ; 12t, 2 bytes
.j1985\@:
	jr .j1986\@ ; 12t, 2 bytes
.j1986\@:
	jr .j1987\@ ; 12t, 2 bytes
.j1987\@:
	jr .j1988\@ ; 12t, 2 bytes
.j1988\@:
	jr .j1989\@ ; 12t, 2 bytes
.j1989\@:
	jr .j1990\@ ; 12t, 2 bytes
.j1990\@:
	jr .j1991\@ ; 12t, 2 bytes
.j1991\@:
	jr .j1992\@ ; 12t, 2 bytes
.j1992\@:
	jr .j1993\@ ; 12t, 2 bytes
.j1993\@:
	jr .j1994\@ ; 12t, 2 bytes
.j1994\@:
	jr .j1995\@ ; 12t, 2 bytes
.j1995\@:
	jr .j1996\@ ; 12t, 2 bytes
.j1996\@:
	jr .j1997\@ ; 12t, 2 bytes
.j1997\@:
	jr .j1998\@ ; 12t, 2 bytes
.j1998\@:
	jr .j1999\@ ; 12t, 2 bytes
.j1999\@:
	ENDM

sleep_230 MACRO
	or 0
	or 0
	jr .j2000\@ ; 12t, 2 bytes
.j2000\@:
	jr .j2001\@ ; 12t, 2 bytes
.j2001\@:
	jr .j2002\@ ; 12t, 2 bytes
.j2002\@:
	jr .j2003\@ ; 12t, 2 bytes
.j2003\@:
	jr .j2004\@ ; 12t, 2 bytes
.j2004\@:
	jr .j2005\@ ; 12t, 2 bytes
.j2005\@:
	jr .j2006\@ ; 12t, 2 bytes
.j2006\@:
	jr .j2007\@ ; 12t, 2 bytes
.j2007\@:
	jr .j2008\@ ; 12t, 2 bytes
.j2008\@:
	jr .j2009\@ ; 12t, 2 bytes
.j2009\@:
	jr .j2010\@ ; 12t, 2 bytes
.j2010\@:
	jr .j2011\@ ; 12t, 2 bytes
.j2011\@:
	jr .j2012\@ ; 12t, 2 bytes
.j2012\@:
	jr .j2013\@ ; 12t, 2 bytes
.j2013\@:
	jr .j2014\@ ; 12t, 2 bytes
.j2014\@:
	jr .j2015\@ ; 12t, 2 bytes
.j2015\@:
	jr .j2016\@ ; 12t, 2 bytes
.j2016\@:
	jr .j2017\@ ; 12t, 2 bytes
.j2017\@:
	ENDM

sleep_231 MACRO
	nop
	nop
	or 0
	jr .j2018\@ ; 12t, 2 bytes
.j2018\@:
	jr .j2019\@ ; 12t, 2 bytes
.j2019\@:
	jr .j2020\@ ; 12t, 2 bytes
.j2020\@:
	jr .j2021\@ ; 12t, 2 bytes
.j2021\@:
	jr .j2022\@ ; 12t, 2 bytes
.j2022\@:
	jr .j2023\@ ; 12t, 2 bytes
.j2023\@:
	jr .j2024\@ ; 12t, 2 bytes
.j2024\@:
	jr .j2025\@ ; 12t, 2 bytes
.j2025\@:
	jr .j2026\@ ; 12t, 2 bytes
.j2026\@:
	jr .j2027\@ ; 12t, 2 bytes
.j2027\@:
	jr .j2028\@ ; 12t, 2 bytes
.j2028\@:
	jr .j2029\@ ; 12t, 2 bytes
.j2029\@:
	jr .j2030\@ ; 12t, 2 bytes
.j2030\@:
	jr .j2031\@ ; 12t, 2 bytes
.j2031\@:
	jr .j2032\@ ; 12t, 2 bytes
.j2032\@:
	jr .j2033\@ ; 12t, 2 bytes
.j2033\@:
	jr .j2034\@ ; 12t, 2 bytes
.j2034\@:
	jr .j2035\@ ; 12t, 2 bytes
.j2035\@:
	ENDM

sleep_232 MACRO
	nop
	jr .j2036\@ ; 12t, 2 bytes
.j2036\@:
	jr .j2037\@ ; 12t, 2 bytes
.j2037\@:
	jr .j2038\@ ; 12t, 2 bytes
.j2038\@:
	jr .j2039\@ ; 12t, 2 bytes
.j2039\@:
	jr .j2040\@ ; 12t, 2 bytes
.j2040\@:
	jr .j2041\@ ; 12t, 2 bytes
.j2041\@:
	jr .j2042\@ ; 12t, 2 bytes
.j2042\@:
	jr .j2043\@ ; 12t, 2 bytes
.j2043\@:
	jr .j2044\@ ; 12t, 2 bytes
.j2044\@:
	jr .j2045\@ ; 12t, 2 bytes
.j2045\@:
	jr .j2046\@ ; 12t, 2 bytes
.j2046\@:
	jr .j2047\@ ; 12t, 2 bytes
.j2047\@:
	jr .j2048\@ ; 12t, 2 bytes
.j2048\@:
	jr .j2049\@ ; 12t, 2 bytes
.j2049\@:
	jr .j2050\@ ; 12t, 2 bytes
.j2050\@:
	jr .j2051\@ ; 12t, 2 bytes
.j2051\@:
	jr .j2052\@ ; 12t, 2 bytes
.j2052\@:
	jr .j2053\@ ; 12t, 2 bytes
.j2053\@:
	jr .j2054\@ ; 12t, 2 bytes
.j2054\@:
	ENDM

sleep_233 MACRO
	or 0
	jp .j2055\@ ; 10t, 3 bytes
.j2055\@:
	jr .j2056\@ ; 12t, 2 bytes
.j2056\@:
	jr .j2057\@ ; 12t, 2 bytes
.j2057\@:
	jr .j2058\@ ; 12t, 2 bytes
.j2058\@:
	jr .j2059\@ ; 12t, 2 bytes
.j2059\@:
	jr .j2060\@ ; 12t, 2 bytes
.j2060\@:
	jr .j2061\@ ; 12t, 2 bytes
.j2061\@:
	jr .j2062\@ ; 12t, 2 bytes
.j2062\@:
	jr .j2063\@ ; 12t, 2 bytes
.j2063\@:
	jr .j2064\@ ; 12t, 2 bytes
.j2064\@:
	jr .j2065\@ ; 12t, 2 bytes
.j2065\@:
	jr .j2066\@ ; 12t, 2 bytes
.j2066\@:
	jr .j2067\@ ; 12t, 2 bytes
.j2067\@:
	jr .j2068\@ ; 12t, 2 bytes
.j2068\@:
	jr .j2069\@ ; 12t, 2 bytes
.j2069\@:
	jr .j2070\@ ; 12t, 2 bytes
.j2070\@:
	jr .j2071\@ ; 12t, 2 bytes
.j2071\@:
	jr .j2072\@ ; 12t, 2 bytes
.j2072\@:
	jr .j2073\@ ; 12t, 2 bytes
.j2073\@:
	ENDM

sleep_234 MACRO
	nop
	or 0
	or 0
	jr .j2074\@ ; 12t, 2 bytes
.j2074\@:
	jr .j2075\@ ; 12t, 2 bytes
.j2075\@:
	jr .j2076\@ ; 12t, 2 bytes
.j2076\@:
	jr .j2077\@ ; 12t, 2 bytes
.j2077\@:
	jr .j2078\@ ; 12t, 2 bytes
.j2078\@:
	jr .j2079\@ ; 12t, 2 bytes
.j2079\@:
	jr .j2080\@ ; 12t, 2 bytes
.j2080\@:
	jr .j2081\@ ; 12t, 2 bytes
.j2081\@:
	jr .j2082\@ ; 12t, 2 bytes
.j2082\@:
	jr .j2083\@ ; 12t, 2 bytes
.j2083\@:
	jr .j2084\@ ; 12t, 2 bytes
.j2084\@:
	jr .j2085\@ ; 12t, 2 bytes
.j2085\@:
	jr .j2086\@ ; 12t, 2 bytes
.j2086\@:
	jr .j2087\@ ; 12t, 2 bytes
.j2087\@:
	jr .j2088\@ ; 12t, 2 bytes
.j2088\@:
	jr .j2089\@ ; 12t, 2 bytes
.j2089\@:
	jr .j2090\@ ; 12t, 2 bytes
.j2090\@:
	jr .j2091\@ ; 12t, 2 bytes
.j2091\@:
	ENDM

sleep_235 MACRO
	or 0
	jr .j2092\@ ; 12t, 2 bytes
.j2092\@:
	jr .j2093\@ ; 12t, 2 bytes
.j2093\@:
	jr .j2094\@ ; 12t, 2 bytes
.j2094\@:
	jr .j2095\@ ; 12t, 2 bytes
.j2095\@:
	jr .j2096\@ ; 12t, 2 bytes
.j2096\@:
	jr .j2097\@ ; 12t, 2 bytes
.j2097\@:
	jr .j2098\@ ; 12t, 2 bytes
.j2098\@:
	jr .j2099\@ ; 12t, 2 bytes
.j2099\@:
	jr .j2100\@ ; 12t, 2 bytes
.j2100\@:
	jr .j2101\@ ; 12t, 2 bytes
.j2101\@:
	jr .j2102\@ ; 12t, 2 bytes
.j2102\@:
	jr .j2103\@ ; 12t, 2 bytes
.j2103\@:
	jr .j2104\@ ; 12t, 2 bytes
.j2104\@:
	jr .j2105\@ ; 12t, 2 bytes
.j2105\@:
	jr .j2106\@ ; 12t, 2 bytes
.j2106\@:
	jr .j2107\@ ; 12t, 2 bytes
.j2107\@:
	jr .j2108\@ ; 12t, 2 bytes
.j2108\@:
	jr .j2109\@ ; 12t, 2 bytes
.j2109\@:
	jr .j2110\@ ; 12t, 2 bytes
.j2110\@:
	ENDM

sleep_236 MACRO
	nop
	nop
	jr .j2111\@ ; 12t, 2 bytes
.j2111\@:
	jr .j2112\@ ; 12t, 2 bytes
.j2112\@:
	jr .j2113\@ ; 12t, 2 bytes
.j2113\@:
	jr .j2114\@ ; 12t, 2 bytes
.j2114\@:
	jr .j2115\@ ; 12t, 2 bytes
.j2115\@:
	jr .j2116\@ ; 12t, 2 bytes
.j2116\@:
	jr .j2117\@ ; 12t, 2 bytes
.j2117\@:
	jr .j2118\@ ; 12t, 2 bytes
.j2118\@:
	jr .j2119\@ ; 12t, 2 bytes
.j2119\@:
	jr .j2120\@ ; 12t, 2 bytes
.j2120\@:
	jr .j2121\@ ; 12t, 2 bytes
.j2121\@:
	jr .j2122\@ ; 12t, 2 bytes
.j2122\@:
	jr .j2123\@ ; 12t, 2 bytes
.j2123\@:
	jr .j2124\@ ; 12t, 2 bytes
.j2124\@:
	jr .j2125\@ ; 12t, 2 bytes
.j2125\@:
	jr .j2126\@ ; 12t, 2 bytes
.j2126\@:
	jr .j2127\@ ; 12t, 2 bytes
.j2127\@:
	jr .j2128\@ ; 12t, 2 bytes
.j2128\@:
	jr .j2129\@ ; 12t, 2 bytes
.j2129\@:
	ENDM

sleep_237 MACRO
	or 0
	or 0
	or 0
	jr .j2130\@ ; 12t, 2 bytes
.j2130\@:
	jr .j2131\@ ; 12t, 2 bytes
.j2131\@:
	jr .j2132\@ ; 12t, 2 bytes
.j2132\@:
	jr .j2133\@ ; 12t, 2 bytes
.j2133\@:
	jr .j2134\@ ; 12t, 2 bytes
.j2134\@:
	jr .j2135\@ ; 12t, 2 bytes
.j2135\@:
	jr .j2136\@ ; 12t, 2 bytes
.j2136\@:
	jr .j2137\@ ; 12t, 2 bytes
.j2137\@:
	jr .j2138\@ ; 12t, 2 bytes
.j2138\@:
	jr .j2139\@ ; 12t, 2 bytes
.j2139\@:
	jr .j2140\@ ; 12t, 2 bytes
.j2140\@:
	jr .j2141\@ ; 12t, 2 bytes
.j2141\@:
	jr .j2142\@ ; 12t, 2 bytes
.j2142\@:
	jr .j2143\@ ; 12t, 2 bytes
.j2143\@:
	jr .j2144\@ ; 12t, 2 bytes
.j2144\@:
	jr .j2145\@ ; 12t, 2 bytes
.j2145\@:
	jr .j2146\@ ; 12t, 2 bytes
.j2146\@:
	jr .j2147\@ ; 12t, 2 bytes
.j2147\@:
	ENDM

sleep_238 MACRO
	jp .j2148\@ ; 10t, 3 bytes
.j2148\@:
	jr .j2149\@ ; 12t, 2 bytes
.j2149\@:
	jr .j2150\@ ; 12t, 2 bytes
.j2150\@:
	jr .j2151\@ ; 12t, 2 bytes
.j2151\@:
	jr .j2152\@ ; 12t, 2 bytes
.j2152\@:
	jr .j2153\@ ; 12t, 2 bytes
.j2153\@:
	jr .j2154\@ ; 12t, 2 bytes
.j2154\@:
	jr .j2155\@ ; 12t, 2 bytes
.j2155\@:
	jr .j2156\@ ; 12t, 2 bytes
.j2156\@:
	jr .j2157\@ ; 12t, 2 bytes
.j2157\@:
	jr .j2158\@ ; 12t, 2 bytes
.j2158\@:
	jr .j2159\@ ; 12t, 2 bytes
.j2159\@:
	jr .j2160\@ ; 12t, 2 bytes
.j2160\@:
	jr .j2161\@ ; 12t, 2 bytes
.j2161\@:
	jr .j2162\@ ; 12t, 2 bytes
.j2162\@:
	jr .j2163\@ ; 12t, 2 bytes
.j2163\@:
	jr .j2164\@ ; 12t, 2 bytes
.j2164\@:
	jr .j2165\@ ; 12t, 2 bytes
.j2165\@:
	jr .j2166\@ ; 12t, 2 bytes
.j2166\@:
	jr .j2167\@ ; 12t, 2 bytes
.j2167\@:
	ENDM

sleep_239 MACRO
	nop
	or 0
	jr .j2168\@ ; 12t, 2 bytes
.j2168\@:
	jr .j2169\@ ; 12t, 2 bytes
.j2169\@:
	jr .j2170\@ ; 12t, 2 bytes
.j2170\@:
	jr .j2171\@ ; 12t, 2 bytes
.j2171\@:
	jr .j2172\@ ; 12t, 2 bytes
.j2172\@:
	jr .j2173\@ ; 12t, 2 bytes
.j2173\@:
	jr .j2174\@ ; 12t, 2 bytes
.j2174\@:
	jr .j2175\@ ; 12t, 2 bytes
.j2175\@:
	jr .j2176\@ ; 12t, 2 bytes
.j2176\@:
	jr .j2177\@ ; 12t, 2 bytes
.j2177\@:
	jr .j2178\@ ; 12t, 2 bytes
.j2178\@:
	jr .j2179\@ ; 12t, 2 bytes
.j2179\@:
	jr .j2180\@ ; 12t, 2 bytes
.j2180\@:
	jr .j2181\@ ; 12t, 2 bytes
.j2181\@:
	jr .j2182\@ ; 12t, 2 bytes
.j2182\@:
	jr .j2183\@ ; 12t, 2 bytes
.j2183\@:
	jr .j2184\@ ; 12t, 2 bytes
.j2184\@:
	jr .j2185\@ ; 12t, 2 bytes
.j2185\@:
	jr .j2186\@ ; 12t, 2 bytes
.j2186\@:
	ENDM

sleep_240 MACRO
	jr .j2187\@ ; 12t, 2 bytes
.j2187\@:
	jr .j2188\@ ; 12t, 2 bytes
.j2188\@:
	jr .j2189\@ ; 12t, 2 bytes
.j2189\@:
	jr .j2190\@ ; 12t, 2 bytes
.j2190\@:
	jr .j2191\@ ; 12t, 2 bytes
.j2191\@:
	jr .j2192\@ ; 12t, 2 bytes
.j2192\@:
	jr .j2193\@ ; 12t, 2 bytes
.j2193\@:
	jr .j2194\@ ; 12t, 2 bytes
.j2194\@:
	jr .j2195\@ ; 12t, 2 bytes
.j2195\@:
	jr .j2196\@ ; 12t, 2 bytes
.j2196\@:
	jr .j2197\@ ; 12t, 2 bytes
.j2197\@:
	jr .j2198\@ ; 12t, 2 bytes
.j2198\@:
	jr .j2199\@ ; 12t, 2 bytes
.j2199\@:
	jr .j2200\@ ; 12t, 2 bytes
.j2200\@:
	jr .j2201\@ ; 12t, 2 bytes
.j2201\@:
	jr .j2202\@ ; 12t, 2 bytes
.j2202\@:
	jr .j2203\@ ; 12t, 2 bytes
.j2203\@:
	jr .j2204\@ ; 12t, 2 bytes
.j2204\@:
	jr .j2205\@ ; 12t, 2 bytes
.j2205\@:
	jr .j2206\@ ; 12t, 2 bytes
.j2206\@:
	ENDM

sleep_241 MACRO
	nop
	or 0
	or 0
	or 0
	jr .j2207\@ ; 12t, 2 bytes
.j2207\@:
	jr .j2208\@ ; 12t, 2 bytes
.j2208\@:
	jr .j2209\@ ; 12t, 2 bytes
.j2209\@:
	jr .j2210\@ ; 12t, 2 bytes
.j2210\@:
	jr .j2211\@ ; 12t, 2 bytes
.j2211\@:
	jr .j2212\@ ; 12t, 2 bytes
.j2212\@:
	jr .j2213\@ ; 12t, 2 bytes
.j2213\@:
	jr .j2214\@ ; 12t, 2 bytes
.j2214\@:
	jr .j2215\@ ; 12t, 2 bytes
.j2215\@:
	jr .j2216\@ ; 12t, 2 bytes
.j2216\@:
	jr .j2217\@ ; 12t, 2 bytes
.j2217\@:
	jr .j2218\@ ; 12t, 2 bytes
.j2218\@:
	jr .j2219\@ ; 12t, 2 bytes
.j2219\@:
	jr .j2220\@ ; 12t, 2 bytes
.j2220\@:
	jr .j2221\@ ; 12t, 2 bytes
.j2221\@:
	jr .j2222\@ ; 12t, 2 bytes
.j2222\@:
	jr .j2223\@ ; 12t, 2 bytes
.j2223\@:
	jr .j2224\@ ; 12t, 2 bytes
.j2224\@:
	ENDM

sleep_242 MACRO
	or 0
	or 0
	jr .j2225\@ ; 12t, 2 bytes
.j2225\@:
	jr .j2226\@ ; 12t, 2 bytes
.j2226\@:
	jr .j2227\@ ; 12t, 2 bytes
.j2227\@:
	jr .j2228\@ ; 12t, 2 bytes
.j2228\@:
	jr .j2229\@ ; 12t, 2 bytes
.j2229\@:
	jr .j2230\@ ; 12t, 2 bytes
.j2230\@:
	jr .j2231\@ ; 12t, 2 bytes
.j2231\@:
	jr .j2232\@ ; 12t, 2 bytes
.j2232\@:
	jr .j2233\@ ; 12t, 2 bytes
.j2233\@:
	jr .j2234\@ ; 12t, 2 bytes
.j2234\@:
	jr .j2235\@ ; 12t, 2 bytes
.j2235\@:
	jr .j2236\@ ; 12t, 2 bytes
.j2236\@:
	jr .j2237\@ ; 12t, 2 bytes
.j2237\@:
	jr .j2238\@ ; 12t, 2 bytes
.j2238\@:
	jr .j2239\@ ; 12t, 2 bytes
.j2239\@:
	jr .j2240\@ ; 12t, 2 bytes
.j2240\@:
	jr .j2241\@ ; 12t, 2 bytes
.j2241\@:
	jr .j2242\@ ; 12t, 2 bytes
.j2242\@:
	jr .j2243\@ ; 12t, 2 bytes
.j2243\@:
	ENDM

sleep_243 MACRO
	nop
	nop
	or 0
	jr .j2244\@ ; 12t, 2 bytes
.j2244\@:
	jr .j2245\@ ; 12t, 2 bytes
.j2245\@:
	jr .j2246\@ ; 12t, 2 bytes
.j2246\@:
	jr .j2247\@ ; 12t, 2 bytes
.j2247\@:
	jr .j2248\@ ; 12t, 2 bytes
.j2248\@:
	jr .j2249\@ ; 12t, 2 bytes
.j2249\@:
	jr .j2250\@ ; 12t, 2 bytes
.j2250\@:
	jr .j2251\@ ; 12t, 2 bytes
.j2251\@:
	jr .j2252\@ ; 12t, 2 bytes
.j2252\@:
	jr .j2253\@ ; 12t, 2 bytes
.j2253\@:
	jr .j2254\@ ; 12t, 2 bytes
.j2254\@:
	jr .j2255\@ ; 12t, 2 bytes
.j2255\@:
	jr .j2256\@ ; 12t, 2 bytes
.j2256\@:
	jr .j2257\@ ; 12t, 2 bytes
.j2257\@:
	jr .j2258\@ ; 12t, 2 bytes
.j2258\@:
	jr .j2259\@ ; 12t, 2 bytes
.j2259\@:
	jr .j2260\@ ; 12t, 2 bytes
.j2260\@:
	jr .j2261\@ ; 12t, 2 bytes
.j2261\@:
	jr .j2262\@ ; 12t, 2 bytes
.j2262\@:
	ENDM

sleep_244 MACRO
	nop
	jr .j2263\@ ; 12t, 2 bytes
.j2263\@:
	jr .j2264\@ ; 12t, 2 bytes
.j2264\@:
	jr .j2265\@ ; 12t, 2 bytes
.j2265\@:
	jr .j2266\@ ; 12t, 2 bytes
.j2266\@:
	jr .j2267\@ ; 12t, 2 bytes
.j2267\@:
	jr .j2268\@ ; 12t, 2 bytes
.j2268\@:
	jr .j2269\@ ; 12t, 2 bytes
.j2269\@:
	jr .j2270\@ ; 12t, 2 bytes
.j2270\@:
	jr .j2271\@ ; 12t, 2 bytes
.j2271\@:
	jr .j2272\@ ; 12t, 2 bytes
.j2272\@:
	jr .j2273\@ ; 12t, 2 bytes
.j2273\@:
	jr .j2274\@ ; 12t, 2 bytes
.j2274\@:
	jr .j2275\@ ; 12t, 2 bytes
.j2275\@:
	jr .j2276\@ ; 12t, 2 bytes
.j2276\@:
	jr .j2277\@ ; 12t, 2 bytes
.j2277\@:
	jr .j2278\@ ; 12t, 2 bytes
.j2278\@:
	jr .j2279\@ ; 12t, 2 bytes
.j2279\@:
	jr .j2280\@ ; 12t, 2 bytes
.j2280\@:
	jr .j2281\@ ; 12t, 2 bytes
.j2281\@:
	jr .j2282\@ ; 12t, 2 bytes
.j2282\@:
	ENDM

sleep_245 MACRO
	or 0
	jp .j2283\@ ; 10t, 3 bytes
.j2283\@:
	jr .j2284\@ ; 12t, 2 bytes
.j2284\@:
	jr .j2285\@ ; 12t, 2 bytes
.j2285\@:
	jr .j2286\@ ; 12t, 2 bytes
.j2286\@:
	jr .j2287\@ ; 12t, 2 bytes
.j2287\@:
	jr .j2288\@ ; 12t, 2 bytes
.j2288\@:
	jr .j2289\@ ; 12t, 2 bytes
.j2289\@:
	jr .j2290\@ ; 12t, 2 bytes
.j2290\@:
	jr .j2291\@ ; 12t, 2 bytes
.j2291\@:
	jr .j2292\@ ; 12t, 2 bytes
.j2292\@:
	jr .j2293\@ ; 12t, 2 bytes
.j2293\@:
	jr .j2294\@ ; 12t, 2 bytes
.j2294\@:
	jr .j2295\@ ; 12t, 2 bytes
.j2295\@:
	jr .j2296\@ ; 12t, 2 bytes
.j2296\@:
	jr .j2297\@ ; 12t, 2 bytes
.j2297\@:
	jr .j2298\@ ; 12t, 2 bytes
.j2298\@:
	jr .j2299\@ ; 12t, 2 bytes
.j2299\@:
	jr .j2300\@ ; 12t, 2 bytes
.j2300\@:
	jr .j2301\@ ; 12t, 2 bytes
.j2301\@:
	jr .j2302\@ ; 12t, 2 bytes
.j2302\@:
	ENDM

sleep_246 MACRO
	nop
	or 0
	or 0
	jr .j2303\@ ; 12t, 2 bytes
.j2303\@:
	jr .j2304\@ ; 12t, 2 bytes
.j2304\@:
	jr .j2305\@ ; 12t, 2 bytes
.j2305\@:
	jr .j2306\@ ; 12t, 2 bytes
.j2306\@:
	jr .j2307\@ ; 12t, 2 bytes
.j2307\@:
	jr .j2308\@ ; 12t, 2 bytes
.j2308\@:
	jr .j2309\@ ; 12t, 2 bytes
.j2309\@:
	jr .j2310\@ ; 12t, 2 bytes
.j2310\@:
	jr .j2311\@ ; 12t, 2 bytes
.j2311\@:
	jr .j2312\@ ; 12t, 2 bytes
.j2312\@:
	jr .j2313\@ ; 12t, 2 bytes
.j2313\@:
	jr .j2314\@ ; 12t, 2 bytes
.j2314\@:
	jr .j2315\@ ; 12t, 2 bytes
.j2315\@:
	jr .j2316\@ ; 12t, 2 bytes
.j2316\@:
	jr .j2317\@ ; 12t, 2 bytes
.j2317\@:
	jr .j2318\@ ; 12t, 2 bytes
.j2318\@:
	jr .j2319\@ ; 12t, 2 bytes
.j2319\@:
	jr .j2320\@ ; 12t, 2 bytes
.j2320\@:
	jr .j2321\@ ; 12t, 2 bytes
.j2321\@:
	ENDM

sleep_247 MACRO
	or 0
	jr .j2322\@ ; 12t, 2 bytes
.j2322\@:
	jr .j2323\@ ; 12t, 2 bytes
.j2323\@:
	jr .j2324\@ ; 12t, 2 bytes
.j2324\@:
	jr .j2325\@ ; 12t, 2 bytes
.j2325\@:
	jr .j2326\@ ; 12t, 2 bytes
.j2326\@:
	jr .j2327\@ ; 12t, 2 bytes
.j2327\@:
	jr .j2328\@ ; 12t, 2 bytes
.j2328\@:
	jr .j2329\@ ; 12t, 2 bytes
.j2329\@:
	jr .j2330\@ ; 12t, 2 bytes
.j2330\@:
	jr .j2331\@ ; 12t, 2 bytes
.j2331\@:
	jr .j2332\@ ; 12t, 2 bytes
.j2332\@:
	jr .j2333\@ ; 12t, 2 bytes
.j2333\@:
	jr .j2334\@ ; 12t, 2 bytes
.j2334\@:
	jr .j2335\@ ; 12t, 2 bytes
.j2335\@:
	jr .j2336\@ ; 12t, 2 bytes
.j2336\@:
	jr .j2337\@ ; 12t, 2 bytes
.j2337\@:
	jr .j2338\@ ; 12t, 2 bytes
.j2338\@:
	jr .j2339\@ ; 12t, 2 bytes
.j2339\@:
	jr .j2340\@ ; 12t, 2 bytes
.j2340\@:
	jr .j2341\@ ; 12t, 2 bytes
.j2341\@:
	ENDM

sleep_248 MACRO
	nop
	nop
	jr .j2342\@ ; 12t, 2 bytes
.j2342\@:
	jr .j2343\@ ; 12t, 2 bytes
.j2343\@:
	jr .j2344\@ ; 12t, 2 bytes
.j2344\@:
	jr .j2345\@ ; 12t, 2 bytes
.j2345\@:
	jr .j2346\@ ; 12t, 2 bytes
.j2346\@:
	jr .j2347\@ ; 12t, 2 bytes
.j2347\@:
	jr .j2348\@ ; 12t, 2 bytes
.j2348\@:
	jr .j2349\@ ; 12t, 2 bytes
.j2349\@:
	jr .j2350\@ ; 12t, 2 bytes
.j2350\@:
	jr .j2351\@ ; 12t, 2 bytes
.j2351\@:
	jr .j2352\@ ; 12t, 2 bytes
.j2352\@:
	jr .j2353\@ ; 12t, 2 bytes
.j2353\@:
	jr .j2354\@ ; 12t, 2 bytes
.j2354\@:
	jr .j2355\@ ; 12t, 2 bytes
.j2355\@:
	jr .j2356\@ ; 12t, 2 bytes
.j2356\@:
	jr .j2357\@ ; 12t, 2 bytes
.j2357\@:
	jr .j2358\@ ; 12t, 2 bytes
.j2358\@:
	jr .j2359\@ ; 12t, 2 bytes
.j2359\@:
	jr .j2360\@ ; 12t, 2 bytes
.j2360\@:
	jr .j2361\@ ; 12t, 2 bytes
.j2361\@:
	ENDM

sleep_249 MACRO
	or 0
	or 0
	or 0
	jr .j2362\@ ; 12t, 2 bytes
.j2362\@:
	jr .j2363\@ ; 12t, 2 bytes
.j2363\@:
	jr .j2364\@ ; 12t, 2 bytes
.j2364\@:
	jr .j2365\@ ; 12t, 2 bytes
.j2365\@:
	jr .j2366\@ ; 12t, 2 bytes
.j2366\@:
	jr .j2367\@ ; 12t, 2 bytes
.j2367\@:
	jr .j2368\@ ; 12t, 2 bytes
.j2368\@:
	jr .j2369\@ ; 12t, 2 bytes
.j2369\@:
	jr .j2370\@ ; 12t, 2 bytes
.j2370\@:
	jr .j2371\@ ; 12t, 2 bytes
.j2371\@:
	jr .j2372\@ ; 12t, 2 bytes
.j2372\@:
	jr .j2373\@ ; 12t, 2 bytes
.j2373\@:
	jr .j2374\@ ; 12t, 2 bytes
.j2374\@:
	jr .j2375\@ ; 12t, 2 bytes
.j2375\@:
	jr .j2376\@ ; 12t, 2 bytes
.j2376\@:
	jr .j2377\@ ; 12t, 2 bytes
.j2377\@:
	jr .j2378\@ ; 12t, 2 bytes
.j2378\@:
	jr .j2379\@ ; 12t, 2 bytes
.j2379\@:
	jr .j2380\@ ; 12t, 2 bytes
.j2380\@:
	ENDM

sleep_250 MACRO
	jp .j2381\@ ; 10t, 3 bytes
.j2381\@:
	jr .j2382\@ ; 12t, 2 bytes
.j2382\@:
	jr .j2383\@ ; 12t, 2 bytes
.j2383\@:
	jr .j2384\@ ; 12t, 2 bytes
.j2384\@:
	jr .j2385\@ ; 12t, 2 bytes
.j2385\@:
	jr .j2386\@ ; 12t, 2 bytes
.j2386\@:
	jr .j2387\@ ; 12t, 2 bytes
.j2387\@:
	jr .j2388\@ ; 12t, 2 bytes
.j2388\@:
	jr .j2389\@ ; 12t, 2 bytes
.j2389\@:
	jr .j2390\@ ; 12t, 2 bytes
.j2390\@:
	jr .j2391\@ ; 12t, 2 bytes
.j2391\@:
	jr .j2392\@ ; 12t, 2 bytes
.j2392\@:
	jr .j2393\@ ; 12t, 2 bytes
.j2393\@:
	jr .j2394\@ ; 12t, 2 bytes
.j2394\@:
	jr .j2395\@ ; 12t, 2 bytes
.j2395\@:
	jr .j2396\@ ; 12t, 2 bytes
.j2396\@:
	jr .j2397\@ ; 12t, 2 bytes
.j2397\@:
	jr .j2398\@ ; 12t, 2 bytes
.j2398\@:
	jr .j2399\@ ; 12t, 2 bytes
.j2399\@:
	jr .j2400\@ ; 12t, 2 bytes
.j2400\@:
	jr .j2401\@ ; 12t, 2 bytes
.j2401\@:
	ENDM

sleep_251 MACRO
	nop
	or 0
	jr .j2402\@ ; 12t, 2 bytes
.j2402\@:
	jr .j2403\@ ; 12t, 2 bytes
.j2403\@:
	jr .j2404\@ ; 12t, 2 bytes
.j2404\@:
	jr .j2405\@ ; 12t, 2 bytes
.j2405\@:
	jr .j2406\@ ; 12t, 2 bytes
.j2406\@:
	jr .j2407\@ ; 12t, 2 bytes
.j2407\@:
	jr .j2408\@ ; 12t, 2 bytes
.j2408\@:
	jr .j2409\@ ; 12t, 2 bytes
.j2409\@:
	jr .j2410\@ ; 12t, 2 bytes
.j2410\@:
	jr .j2411\@ ; 12t, 2 bytes
.j2411\@:
	jr .j2412\@ ; 12t, 2 bytes
.j2412\@:
	jr .j2413\@ ; 12t, 2 bytes
.j2413\@:
	jr .j2414\@ ; 12t, 2 bytes
.j2414\@:
	jr .j2415\@ ; 12t, 2 bytes
.j2415\@:
	jr .j2416\@ ; 12t, 2 bytes
.j2416\@:
	jr .j2417\@ ; 12t, 2 bytes
.j2417\@:
	jr .j2418\@ ; 12t, 2 bytes
.j2418\@:
	jr .j2419\@ ; 12t, 2 bytes
.j2419\@:
	jr .j2420\@ ; 12t, 2 bytes
.j2420\@:
	jr .j2421\@ ; 12t, 2 bytes
.j2421\@:
	ENDM

sleep_252 MACRO
	jr .j2422\@ ; 12t, 2 bytes
.j2422\@:
	jr .j2423\@ ; 12t, 2 bytes
.j2423\@:
	jr .j2424\@ ; 12t, 2 bytes
.j2424\@:
	jr .j2425\@ ; 12t, 2 bytes
.j2425\@:
	jr .j2426\@ ; 12t, 2 bytes
.j2426\@:
	jr .j2427\@ ; 12t, 2 bytes
.j2427\@:
	jr .j2428\@ ; 12t, 2 bytes
.j2428\@:
	jr .j2429\@ ; 12t, 2 bytes
.j2429\@:
	jr .j2430\@ ; 12t, 2 bytes
.j2430\@:
	jr .j2431\@ ; 12t, 2 bytes
.j2431\@:
	jr .j2432\@ ; 12t, 2 bytes
.j2432\@:
	jr .j2433\@ ; 12t, 2 bytes
.j2433\@:
	jr .j2434\@ ; 12t, 2 bytes
.j2434\@:
	jr .j2435\@ ; 12t, 2 bytes
.j2435\@:
	jr .j2436\@ ; 12t, 2 bytes
.j2436\@:
	jr .j2437\@ ; 12t, 2 bytes
.j2437\@:
	jr .j2438\@ ; 12t, 2 bytes
.j2438\@:
	jr .j2439\@ ; 12t, 2 bytes
.j2439\@:
	jr .j2440\@ ; 12t, 2 bytes
.j2440\@:
	jr .j2441\@ ; 12t, 2 bytes
.j2441\@:
	jr .j2442\@ ; 12t, 2 bytes
.j2442\@:
	ENDM

sleep_253 MACRO
	nop
	or 0
	or 0
	or 0
	jr .j2443\@ ; 12t, 2 bytes
.j2443\@:
	jr .j2444\@ ; 12t, 2 bytes
.j2444\@:
	jr .j2445\@ ; 12t, 2 bytes
.j2445\@:
	jr .j2446\@ ; 12t, 2 bytes
.j2446\@:
	jr .j2447\@ ; 12t, 2 bytes
.j2447\@:
	jr .j2448\@ ; 12t, 2 bytes
.j2448\@:
	jr .j2449\@ ; 12t, 2 bytes
.j2449\@:
	jr .j2450\@ ; 12t, 2 bytes
.j2450\@:
	jr .j2451\@ ; 12t, 2 bytes
.j2451\@:
	jr .j2452\@ ; 12t, 2 bytes
.j2452\@:
	jr .j2453\@ ; 12t, 2 bytes
.j2453\@:
	jr .j2454\@ ; 12t, 2 bytes
.j2454\@:
	jr .j2455\@ ; 12t, 2 bytes
.j2455\@:
	jr .j2456\@ ; 12t, 2 bytes
.j2456\@:
	jr .j2457\@ ; 12t, 2 bytes
.j2457\@:
	jr .j2458\@ ; 12t, 2 bytes
.j2458\@:
	jr .j2459\@ ; 12t, 2 bytes
.j2459\@:
	jr .j2460\@ ; 12t, 2 bytes
.j2460\@:
	jr .j2461\@ ; 12t, 2 bytes
.j2461\@:
	ENDM

sleep_254 MACRO
	or 0
	or 0
	jr .j2462\@ ; 12t, 2 bytes
.j2462\@:
	jr .j2463\@ ; 12t, 2 bytes
.j2463\@:
	jr .j2464\@ ; 12t, 2 bytes
.j2464\@:
	jr .j2465\@ ; 12t, 2 bytes
.j2465\@:
	jr .j2466\@ ; 12t, 2 bytes
.j2466\@:
	jr .j2467\@ ; 12t, 2 bytes
.j2467\@:
	jr .j2468\@ ; 12t, 2 bytes
.j2468\@:
	jr .j2469\@ ; 12t, 2 bytes
.j2469\@:
	jr .j2470\@ ; 12t, 2 bytes
.j2470\@:
	jr .j2471\@ ; 12t, 2 bytes
.j2471\@:
	jr .j2472\@ ; 12t, 2 bytes
.j2472\@:
	jr .j2473\@ ; 12t, 2 bytes
.j2473\@:
	jr .j2474\@ ; 12t, 2 bytes
.j2474\@:
	jr .j2475\@ ; 12t, 2 bytes
.j2475\@:
	jr .j2476\@ ; 12t, 2 bytes
.j2476\@:
	jr .j2477\@ ; 12t, 2 bytes
.j2477\@:
	jr .j2478\@ ; 12t, 2 bytes
.j2478\@:
	jr .j2479\@ ; 12t, 2 bytes
.j2479\@:
	jr .j2480\@ ; 12t, 2 bytes
.j2480\@:
	jr .j2481\@ ; 12t, 2 bytes
.j2481\@:
	ENDM

sleep_255 MACRO
	nop
	nop
	or 0
	jr .j2482\@ ; 12t, 2 bytes
.j2482\@:
	jr .j2483\@ ; 12t, 2 bytes
.j2483\@:
	jr .j2484\@ ; 12t, 2 bytes
.j2484\@:
	jr .j2485\@ ; 12t, 2 bytes
.j2485\@:
	jr .j2486\@ ; 12t, 2 bytes
.j2486\@:
	jr .j2487\@ ; 12t, 2 bytes
.j2487\@:
	jr .j2488\@ ; 12t, 2 bytes
.j2488\@:
	jr .j2489\@ ; 12t, 2 bytes
.j2489\@:
	jr .j2490\@ ; 12t, 2 bytes
.j2490\@:
	jr .j2491\@ ; 12t, 2 bytes
.j2491\@:
	jr .j2492\@ ; 12t, 2 bytes
.j2492\@:
	jr .j2493\@ ; 12t, 2 bytes
.j2493\@:
	jr .j2494\@ ; 12t, 2 bytes
.j2494\@:
	jr .j2495\@ ; 12t, 2 bytes
.j2495\@:
	jr .j2496\@ ; 12t, 2 bytes
.j2496\@:
	jr .j2497\@ ; 12t, 2 bytes
.j2497\@:
	jr .j2498\@ ; 12t, 2 bytes
.j2498\@:
	jr .j2499\@ ; 12t, 2 bytes
.j2499\@:
	jr .j2500\@ ; 12t, 2 bytes
.j2500\@:
	jr .j2501\@ ; 12t, 2 bytes
.j2501\@:
	ENDM

sleep_256 MACRO
	nop
	jr .j2502\@ ; 12t, 2 bytes
.j2502\@:
	jr .j2503\@ ; 12t, 2 bytes
.j2503\@:
	jr .j2504\@ ; 12t, 2 bytes
.j2504\@:
	jr .j2505\@ ; 12t, 2 bytes
.j2505\@:
	jr .j2506\@ ; 12t, 2 bytes
.j2506\@:
	jr .j2507\@ ; 12t, 2 bytes
.j2507\@:
	jr .j2508\@ ; 12t, 2 bytes
.j2508\@:
	jr .j2509\@ ; 12t, 2 bytes
.j2509\@:
	jr .j2510\@ ; 12t, 2 bytes
.j2510\@:
	jr .j2511\@ ; 12t, 2 bytes
.j2511\@:
	jr .j2512\@ ; 12t, 2 bytes
.j2512\@:
	jr .j2513\@ ; 12t, 2 bytes
.j2513\@:
	jr .j2514\@ ; 12t, 2 bytes
.j2514\@:
	jr .j2515\@ ; 12t, 2 bytes
.j2515\@:
	jr .j2516\@ ; 12t, 2 bytes
.j2516\@:
	jr .j2517\@ ; 12t, 2 bytes
.j2517\@:
	jr .j2518\@ ; 12t, 2 bytes
.j2518\@:
	jr .j2519\@ ; 12t, 2 bytes
.j2519\@:
	jr .j2520\@ ; 12t, 2 bytes
.j2520\@:
	jr .j2521\@ ; 12t, 2 bytes
.j2521\@:
	jr .j2522\@ ; 12t, 2 bytes
.j2522\@:
	ENDM

sleep_257 MACRO
	or 0
	jp .j2523\@ ; 10t, 3 bytes
.j2523\@:
	jr .j2524\@ ; 12t, 2 bytes
.j2524\@:
	jr .j2525\@ ; 12t, 2 bytes
.j2525\@:
	jr .j2526\@ ; 12t, 2 bytes
.j2526\@:
	jr .j2527\@ ; 12t, 2 bytes
.j2527\@:
	jr .j2528\@ ; 12t, 2 bytes
.j2528\@:
	jr .j2529\@ ; 12t, 2 bytes
.j2529\@:
	jr .j2530\@ ; 12t, 2 bytes
.j2530\@:
	jr .j2531\@ ; 12t, 2 bytes
.j2531\@:
	jr .j2532\@ ; 12t, 2 bytes
.j2532\@:
	jr .j2533\@ ; 12t, 2 bytes
.j2533\@:
	jr .j2534\@ ; 12t, 2 bytes
.j2534\@:
	jr .j2535\@ ; 12t, 2 bytes
.j2535\@:
	jr .j2536\@ ; 12t, 2 bytes
.j2536\@:
	jr .j2537\@ ; 12t, 2 bytes
.j2537\@:
	jr .j2538\@ ; 12t, 2 bytes
.j2538\@:
	jr .j2539\@ ; 12t, 2 bytes
.j2539\@:
	jr .j2540\@ ; 12t, 2 bytes
.j2540\@:
	jr .j2541\@ ; 12t, 2 bytes
.j2541\@:
	jr .j2542\@ ; 12t, 2 bytes
.j2542\@:
	jr .j2543\@ ; 12t, 2 bytes
.j2543\@:
	ENDM

sleep_258 MACRO
	nop
	or 0
	or 0
	jr .j2544\@ ; 12t, 2 bytes
.j2544\@:
	jr .j2545\@ ; 12t, 2 bytes
.j2545\@:
	jr .j2546\@ ; 12t, 2 bytes
.j2546\@:
	jr .j2547\@ ; 12t, 2 bytes
.j2547\@:
	jr .j2548\@ ; 12t, 2 bytes
.j2548\@:
	jr .j2549\@ ; 12t, 2 bytes
.j2549\@:
	jr .j2550\@ ; 12t, 2 bytes
.j2550\@:
	jr .j2551\@ ; 12t, 2 bytes
.j2551\@:
	jr .j2552\@ ; 12t, 2 bytes
.j2552\@:
	jr .j2553\@ ; 12t, 2 bytes
.j2553\@:
	jr .j2554\@ ; 12t, 2 bytes
.j2554\@:
	jr .j2555\@ ; 12t, 2 bytes
.j2555\@:
	jr .j2556\@ ; 12t, 2 bytes
.j2556\@:
	jr .j2557\@ ; 12t, 2 bytes
.j2557\@:
	jr .j2558\@ ; 12t, 2 bytes
.j2558\@:
	jr .j2559\@ ; 12t, 2 bytes
.j2559\@:
	jr .j2560\@ ; 12t, 2 bytes
.j2560\@:
	jr .j2561\@ ; 12t, 2 bytes
.j2561\@:
	jr .j2562\@ ; 12t, 2 bytes
.j2562\@:
	jr .j2563\@ ; 12t, 2 bytes
.j2563\@:
	ENDM

sleep_259 MACRO
	or 0
	jr .j2564\@ ; 12t, 2 bytes
.j2564\@:
	jr .j2565\@ ; 12t, 2 bytes
.j2565\@:
	jr .j2566\@ ; 12t, 2 bytes
.j2566\@:
	jr .j2567\@ ; 12t, 2 bytes
.j2567\@:
	jr .j2568\@ ; 12t, 2 bytes
.j2568\@:
	jr .j2569\@ ; 12t, 2 bytes
.j2569\@:
	jr .j2570\@ ; 12t, 2 bytes
.j2570\@:
	jr .j2571\@ ; 12t, 2 bytes
.j2571\@:
	jr .j2572\@ ; 12t, 2 bytes
.j2572\@:
	jr .j2573\@ ; 12t, 2 bytes
.j2573\@:
	jr .j2574\@ ; 12t, 2 bytes
.j2574\@:
	jr .j2575\@ ; 12t, 2 bytes
.j2575\@:
	jr .j2576\@ ; 12t, 2 bytes
.j2576\@:
	jr .j2577\@ ; 12t, 2 bytes
.j2577\@:
	jr .j2578\@ ; 12t, 2 bytes
.j2578\@:
	jr .j2579\@ ; 12t, 2 bytes
.j2579\@:
	jr .j2580\@ ; 12t, 2 bytes
.j2580\@:
	jr .j2581\@ ; 12t, 2 bytes
.j2581\@:
	jr .j2582\@ ; 12t, 2 bytes
.j2582\@:
	jr .j2583\@ ; 12t, 2 bytes
.j2583\@:
	jr .j2584\@ ; 12t, 2 bytes
.j2584\@:
	ENDM

sleep_260 MACRO
	nop
	nop
	jr .j2585\@ ; 12t, 2 bytes
.j2585\@:
	jr .j2586\@ ; 12t, 2 bytes
.j2586\@:
	jr .j2587\@ ; 12t, 2 bytes
.j2587\@:
	jr .j2588\@ ; 12t, 2 bytes
.j2588\@:
	jr .j2589\@ ; 12t, 2 bytes
.j2589\@:
	jr .j2590\@ ; 12t, 2 bytes
.j2590\@:
	jr .j2591\@ ; 12t, 2 bytes
.j2591\@:
	jr .j2592\@ ; 12t, 2 bytes
.j2592\@:
	jr .j2593\@ ; 12t, 2 bytes
.j2593\@:
	jr .j2594\@ ; 12t, 2 bytes
.j2594\@:
	jr .j2595\@ ; 12t, 2 bytes
.j2595\@:
	jr .j2596\@ ; 12t, 2 bytes
.j2596\@:
	jr .j2597\@ ; 12t, 2 bytes
.j2597\@:
	jr .j2598\@ ; 12t, 2 bytes
.j2598\@:
	jr .j2599\@ ; 12t, 2 bytes
.j2599\@:
	jr .j2600\@ ; 12t, 2 bytes
.j2600\@:
	jr .j2601\@ ; 12t, 2 bytes
.j2601\@:
	jr .j2602\@ ; 12t, 2 bytes
.j2602\@:
	jr .j2603\@ ; 12t, 2 bytes
.j2603\@:
	jr .j2604\@ ; 12t, 2 bytes
.j2604\@:
	jr .j2605\@ ; 12t, 2 bytes
.j2605\@:
	ENDM

sleep_261 MACRO
	or 0
	or 0
	or 0
	jr .j2606\@ ; 12t, 2 bytes
.j2606\@:
	jr .j2607\@ ; 12t, 2 bytes
.j2607\@:
	jr .j2608\@ ; 12t, 2 bytes
.j2608\@:
	jr .j2609\@ ; 12t, 2 bytes
.j2609\@:
	jr .j2610\@ ; 12t, 2 bytes
.j2610\@:
	jr .j2611\@ ; 12t, 2 bytes
.j2611\@:
	jr .j2612\@ ; 12t, 2 bytes
.j2612\@:
	jr .j2613\@ ; 12t, 2 bytes
.j2613\@:
	jr .j2614\@ ; 12t, 2 bytes
.j2614\@:
	jr .j2615\@ ; 12t, 2 bytes
.j2615\@:
	jr .j2616\@ ; 12t, 2 bytes
.j2616\@:
	jr .j2617\@ ; 12t, 2 bytes
.j2617\@:
	jr .j2618\@ ; 12t, 2 bytes
.j2618\@:
	jr .j2619\@ ; 12t, 2 bytes
.j2619\@:
	jr .j2620\@ ; 12t, 2 bytes
.j2620\@:
	jr .j2621\@ ; 12t, 2 bytes
.j2621\@:
	jr .j2622\@ ; 12t, 2 bytes
.j2622\@:
	jr .j2623\@ ; 12t, 2 bytes
.j2623\@:
	jr .j2624\@ ; 12t, 2 bytes
.j2624\@:
	jr .j2625\@ ; 12t, 2 bytes
.j2625\@:
	ENDM

sleep_262 MACRO
	jp .j2626\@ ; 10t, 3 bytes
.j2626\@:
	jr .j2627\@ ; 12t, 2 bytes
.j2627\@:
	jr .j2628\@ ; 12t, 2 bytes
.j2628\@:
	jr .j2629\@ ; 12t, 2 bytes
.j2629\@:
	jr .j2630\@ ; 12t, 2 bytes
.j2630\@:
	jr .j2631\@ ; 12t, 2 bytes
.j2631\@:
	jr .j2632\@ ; 12t, 2 bytes
.j2632\@:
	jr .j2633\@ ; 12t, 2 bytes
.j2633\@:
	jr .j2634\@ ; 12t, 2 bytes
.j2634\@:
	jr .j2635\@ ; 12t, 2 bytes
.j2635\@:
	jr .j2636\@ ; 12t, 2 bytes
.j2636\@:
	jr .j2637\@ ; 12t, 2 bytes
.j2637\@:
	jr .j2638\@ ; 12t, 2 bytes
.j2638\@:
	jr .j2639\@ ; 12t, 2 bytes
.j2639\@:
	jr .j2640\@ ; 12t, 2 bytes
.j2640\@:
	jr .j2641\@ ; 12t, 2 bytes
.j2641\@:
	jr .j2642\@ ; 12t, 2 bytes
.j2642\@:
	jr .j2643\@ ; 12t, 2 bytes
.j2643\@:
	jr .j2644\@ ; 12t, 2 bytes
.j2644\@:
	jr .j2645\@ ; 12t, 2 bytes
.j2645\@:
	jr .j2646\@ ; 12t, 2 bytes
.j2646\@:
	jr .j2647\@ ; 12t, 2 bytes
.j2647\@:
	ENDM

sleep_263 MACRO
	nop
	or 0
	jr .j2648\@ ; 12t, 2 bytes
.j2648\@:
	jr .j2649\@ ; 12t, 2 bytes
.j2649\@:
	jr .j2650\@ ; 12t, 2 bytes
.j2650\@:
	jr .j2651\@ ; 12t, 2 bytes
.j2651\@:
	jr .j2652\@ ; 12t, 2 bytes
.j2652\@:
	jr .j2653\@ ; 12t, 2 bytes
.j2653\@:
	jr .j2654\@ ; 12t, 2 bytes
.j2654\@:
	jr .j2655\@ ; 12t, 2 bytes
.j2655\@:
	jr .j2656\@ ; 12t, 2 bytes
.j2656\@:
	jr .j2657\@ ; 12t, 2 bytes
.j2657\@:
	jr .j2658\@ ; 12t, 2 bytes
.j2658\@:
	jr .j2659\@ ; 12t, 2 bytes
.j2659\@:
	jr .j2660\@ ; 12t, 2 bytes
.j2660\@:
	jr .j2661\@ ; 12t, 2 bytes
.j2661\@:
	jr .j2662\@ ; 12t, 2 bytes
.j2662\@:
	jr .j2663\@ ; 12t, 2 bytes
.j2663\@:
	jr .j2664\@ ; 12t, 2 bytes
.j2664\@:
	jr .j2665\@ ; 12t, 2 bytes
.j2665\@:
	jr .j2666\@ ; 12t, 2 bytes
.j2666\@:
	jr .j2667\@ ; 12t, 2 bytes
.j2667\@:
	jr .j2668\@ ; 12t, 2 bytes
.j2668\@:
	ENDM

sleep_264 MACRO
	jr .j2669\@ ; 12t, 2 bytes
.j2669\@:
	jr .j2670\@ ; 12t, 2 bytes
.j2670\@:
	jr .j2671\@ ; 12t, 2 bytes
.j2671\@:
	jr .j2672\@ ; 12t, 2 bytes
.j2672\@:
	jr .j2673\@ ; 12t, 2 bytes
.j2673\@:
	jr .j2674\@ ; 12t, 2 bytes
.j2674\@:
	jr .j2675\@ ; 12t, 2 bytes
.j2675\@:
	jr .j2676\@ ; 12t, 2 bytes
.j2676\@:
	jr .j2677\@ ; 12t, 2 bytes
.j2677\@:
	jr .j2678\@ ; 12t, 2 bytes
.j2678\@:
	jr .j2679\@ ; 12t, 2 bytes
.j2679\@:
	jr .j2680\@ ; 12t, 2 bytes
.j2680\@:
	jr .j2681\@ ; 12t, 2 bytes
.j2681\@:
	jr .j2682\@ ; 12t, 2 bytes
.j2682\@:
	jr .j2683\@ ; 12t, 2 bytes
.j2683\@:
	jr .j2684\@ ; 12t, 2 bytes
.j2684\@:
	jr .j2685\@ ; 12t, 2 bytes
.j2685\@:
	jr .j2686\@ ; 12t, 2 bytes
.j2686\@:
	jr .j2687\@ ; 12t, 2 bytes
.j2687\@:
	jr .j2688\@ ; 12t, 2 bytes
.j2688\@:
	jr .j2689\@ ; 12t, 2 bytes
.j2689\@:
	jr .j2690\@ ; 12t, 2 bytes
.j2690\@:
	ENDM

sleep_265 MACRO
	nop
	or 0
	or 0
	or 0
	jr .j2691\@ ; 12t, 2 bytes
.j2691\@:
	jr .j2692\@ ; 12t, 2 bytes
.j2692\@:
	jr .j2693\@ ; 12t, 2 bytes
.j2693\@:
	jr .j2694\@ ; 12t, 2 bytes
.j2694\@:
	jr .j2695\@ ; 12t, 2 bytes
.j2695\@:
	jr .j2696\@ ; 12t, 2 bytes
.j2696\@:
	jr .j2697\@ ; 12t, 2 bytes
.j2697\@:
	jr .j2698\@ ; 12t, 2 bytes
.j2698\@:
	jr .j2699\@ ; 12t, 2 bytes
.j2699\@:
	jr .j2700\@ ; 12t, 2 bytes
.j2700\@:
	jr .j2701\@ ; 12t, 2 bytes
.j2701\@:
	jr .j2702\@ ; 12t, 2 bytes
.j2702\@:
	jr .j2703\@ ; 12t, 2 bytes
.j2703\@:
	jr .j2704\@ ; 12t, 2 bytes
.j2704\@:
	jr .j2705\@ ; 12t, 2 bytes
.j2705\@:
	jr .j2706\@ ; 12t, 2 bytes
.j2706\@:
	jr .j2707\@ ; 12t, 2 bytes
.j2707\@:
	jr .j2708\@ ; 12t, 2 bytes
.j2708\@:
	jr .j2709\@ ; 12t, 2 bytes
.j2709\@:
	jr .j2710\@ ; 12t, 2 bytes
.j2710\@:
	ENDM

sleep_266 MACRO
	or 0
	or 0
	jr .j2711\@ ; 12t, 2 bytes
.j2711\@:
	jr .j2712\@ ; 12t, 2 bytes
.j2712\@:
	jr .j2713\@ ; 12t, 2 bytes
.j2713\@:
	jr .j2714\@ ; 12t, 2 bytes
.j2714\@:
	jr .j2715\@ ; 12t, 2 bytes
.j2715\@:
	jr .j2716\@ ; 12t, 2 bytes
.j2716\@:
	jr .j2717\@ ; 12t, 2 bytes
.j2717\@:
	jr .j2718\@ ; 12t, 2 bytes
.j2718\@:
	jr .j2719\@ ; 12t, 2 bytes
.j2719\@:
	jr .j2720\@ ; 12t, 2 bytes
.j2720\@:
	jr .j2721\@ ; 12t, 2 bytes
.j2721\@:
	jr .j2722\@ ; 12t, 2 bytes
.j2722\@:
	jr .j2723\@ ; 12t, 2 bytes
.j2723\@:
	jr .j2724\@ ; 12t, 2 bytes
.j2724\@:
	jr .j2725\@ ; 12t, 2 bytes
.j2725\@:
	jr .j2726\@ ; 12t, 2 bytes
.j2726\@:
	jr .j2727\@ ; 12t, 2 bytes
.j2727\@:
	jr .j2728\@ ; 12t, 2 bytes
.j2728\@:
	jr .j2729\@ ; 12t, 2 bytes
.j2729\@:
	jr .j2730\@ ; 12t, 2 bytes
.j2730\@:
	jr .j2731\@ ; 12t, 2 bytes
.j2731\@:
	ENDM

sleep_267 MACRO
	nop
	nop
	or 0
	jr .j2732\@ ; 12t, 2 bytes
.j2732\@:
	jr .j2733\@ ; 12t, 2 bytes
.j2733\@:
	jr .j2734\@ ; 12t, 2 bytes
.j2734\@:
	jr .j2735\@ ; 12t, 2 bytes
.j2735\@:
	jr .j2736\@ ; 12t, 2 bytes
.j2736\@:
	jr .j2737\@ ; 12t, 2 bytes
.j2737\@:
	jr .j2738\@ ; 12t, 2 bytes
.j2738\@:
	jr .j2739\@ ; 12t, 2 bytes
.j2739\@:
	jr .j2740\@ ; 12t, 2 bytes
.j2740\@:
	jr .j2741\@ ; 12t, 2 bytes
.j2741\@:
	jr .j2742\@ ; 12t, 2 bytes
.j2742\@:
	jr .j2743\@ ; 12t, 2 bytes
.j2743\@:
	jr .j2744\@ ; 12t, 2 bytes
.j2744\@:
	jr .j2745\@ ; 12t, 2 bytes
.j2745\@:
	jr .j2746\@ ; 12t, 2 bytes
.j2746\@:
	jr .j2747\@ ; 12t, 2 bytes
.j2747\@:
	jr .j2748\@ ; 12t, 2 bytes
.j2748\@:
	jr .j2749\@ ; 12t, 2 bytes
.j2749\@:
	jr .j2750\@ ; 12t, 2 bytes
.j2750\@:
	jr .j2751\@ ; 12t, 2 bytes
.j2751\@:
	jr .j2752\@ ; 12t, 2 bytes
.j2752\@:
	ENDM

sleep_268 MACRO
	nop
	jr .j2753\@ ; 12t, 2 bytes
.j2753\@:
	jr .j2754\@ ; 12t, 2 bytes
.j2754\@:
	jr .j2755\@ ; 12t, 2 bytes
.j2755\@:
	jr .j2756\@ ; 12t, 2 bytes
.j2756\@:
	jr .j2757\@ ; 12t, 2 bytes
.j2757\@:
	jr .j2758\@ ; 12t, 2 bytes
.j2758\@:
	jr .j2759\@ ; 12t, 2 bytes
.j2759\@:
	jr .j2760\@ ; 12t, 2 bytes
.j2760\@:
	jr .j2761\@ ; 12t, 2 bytes
.j2761\@:
	jr .j2762\@ ; 12t, 2 bytes
.j2762\@:
	jr .j2763\@ ; 12t, 2 bytes
.j2763\@:
	jr .j2764\@ ; 12t, 2 bytes
.j2764\@:
	jr .j2765\@ ; 12t, 2 bytes
.j2765\@:
	jr .j2766\@ ; 12t, 2 bytes
.j2766\@:
	jr .j2767\@ ; 12t, 2 bytes
.j2767\@:
	jr .j2768\@ ; 12t, 2 bytes
.j2768\@:
	jr .j2769\@ ; 12t, 2 bytes
.j2769\@:
	jr .j2770\@ ; 12t, 2 bytes
.j2770\@:
	jr .j2771\@ ; 12t, 2 bytes
.j2771\@:
	jr .j2772\@ ; 12t, 2 bytes
.j2772\@:
	jr .j2773\@ ; 12t, 2 bytes
.j2773\@:
	jr .j2774\@ ; 12t, 2 bytes
.j2774\@:
	ENDM

sleep_269 MACRO
	or 0
	jp .j2775\@ ; 10t, 3 bytes
.j2775\@:
	jr .j2776\@ ; 12t, 2 bytes
.j2776\@:
	jr .j2777\@ ; 12t, 2 bytes
.j2777\@:
	jr .j2778\@ ; 12t, 2 bytes
.j2778\@:
	jr .j2779\@ ; 12t, 2 bytes
.j2779\@:
	jr .j2780\@ ; 12t, 2 bytes
.j2780\@:
	jr .j2781\@ ; 12t, 2 bytes
.j2781\@:
	jr .j2782\@ ; 12t, 2 bytes
.j2782\@:
	jr .j2783\@ ; 12t, 2 bytes
.j2783\@:
	jr .j2784\@ ; 12t, 2 bytes
.j2784\@:
	jr .j2785\@ ; 12t, 2 bytes
.j2785\@:
	jr .j2786\@ ; 12t, 2 bytes
.j2786\@:
	jr .j2787\@ ; 12t, 2 bytes
.j2787\@:
	jr .j2788\@ ; 12t, 2 bytes
.j2788\@:
	jr .j2789\@ ; 12t, 2 bytes
.j2789\@:
	jr .j2790\@ ; 12t, 2 bytes
.j2790\@:
	jr .j2791\@ ; 12t, 2 bytes
.j2791\@:
	jr .j2792\@ ; 12t, 2 bytes
.j2792\@:
	jr .j2793\@ ; 12t, 2 bytes
.j2793\@:
	jr .j2794\@ ; 12t, 2 bytes
.j2794\@:
	jr .j2795\@ ; 12t, 2 bytes
.j2795\@:
	jr .j2796\@ ; 12t, 2 bytes
.j2796\@:
	ENDM

sleep_270 MACRO
	nop
	or 0
	or 0
	jr .j2797\@ ; 12t, 2 bytes
.j2797\@:
	jr .j2798\@ ; 12t, 2 bytes
.j2798\@:
	jr .j2799\@ ; 12t, 2 bytes
.j2799\@:
	jr .j2800\@ ; 12t, 2 bytes
.j2800\@:
	jr .j2801\@ ; 12t, 2 bytes
.j2801\@:
	jr .j2802\@ ; 12t, 2 bytes
.j2802\@:
	jr .j2803\@ ; 12t, 2 bytes
.j2803\@:
	jr .j2804\@ ; 12t, 2 bytes
.j2804\@:
	jr .j2805\@ ; 12t, 2 bytes
.j2805\@:
	jr .j2806\@ ; 12t, 2 bytes
.j2806\@:
	jr .j2807\@ ; 12t, 2 bytes
.j2807\@:
	jr .j2808\@ ; 12t, 2 bytes
.j2808\@:
	jr .j2809\@ ; 12t, 2 bytes
.j2809\@:
	jr .j2810\@ ; 12t, 2 bytes
.j2810\@:
	jr .j2811\@ ; 12t, 2 bytes
.j2811\@:
	jr .j2812\@ ; 12t, 2 bytes
.j2812\@:
	jr .j2813\@ ; 12t, 2 bytes
.j2813\@:
	jr .j2814\@ ; 12t, 2 bytes
.j2814\@:
	jr .j2815\@ ; 12t, 2 bytes
.j2815\@:
	jr .j2816\@ ; 12t, 2 bytes
.j2816\@:
	jr .j2817\@ ; 12t, 2 bytes
.j2817\@:
	ENDM

sleep_271 MACRO
	or 0
	jr .j2818\@ ; 12t, 2 bytes
.j2818\@:
	jr .j2819\@ ; 12t, 2 bytes
.j2819\@:
	jr .j2820\@ ; 12t, 2 bytes
.j2820\@:
	jr .j2821\@ ; 12t, 2 bytes
.j2821\@:
	jr .j2822\@ ; 12t, 2 bytes
.j2822\@:
	jr .j2823\@ ; 12t, 2 bytes
.j2823\@:
	jr .j2824\@ ; 12t, 2 bytes
.j2824\@:
	jr .j2825\@ ; 12t, 2 bytes
.j2825\@:
	jr .j2826\@ ; 12t, 2 bytes
.j2826\@:
	jr .j2827\@ ; 12t, 2 bytes
.j2827\@:
	jr .j2828\@ ; 12t, 2 bytes
.j2828\@:
	jr .j2829\@ ; 12t, 2 bytes
.j2829\@:
	jr .j2830\@ ; 12t, 2 bytes
.j2830\@:
	jr .j2831\@ ; 12t, 2 bytes
.j2831\@:
	jr .j2832\@ ; 12t, 2 bytes
.j2832\@:
	jr .j2833\@ ; 12t, 2 bytes
.j2833\@:
	jr .j2834\@ ; 12t, 2 bytes
.j2834\@:
	jr .j2835\@ ; 12t, 2 bytes
.j2835\@:
	jr .j2836\@ ; 12t, 2 bytes
.j2836\@:
	jr .j2837\@ ; 12t, 2 bytes
.j2837\@:
	jr .j2838\@ ; 12t, 2 bytes
.j2838\@:
	jr .j2839\@ ; 12t, 2 bytes
.j2839\@:
	ENDM

sleep_272 MACRO
	nop
	nop
	jr .j2840\@ ; 12t, 2 bytes
.j2840\@:
	jr .j2841\@ ; 12t, 2 bytes
.j2841\@:
	jr .j2842\@ ; 12t, 2 bytes
.j2842\@:
	jr .j2843\@ ; 12t, 2 bytes
.j2843\@:
	jr .j2844\@ ; 12t, 2 bytes
.j2844\@:
	jr .j2845\@ ; 12t, 2 bytes
.j2845\@:
	jr .j2846\@ ; 12t, 2 bytes
.j2846\@:
	jr .j2847\@ ; 12t, 2 bytes
.j2847\@:
	jr .j2848\@ ; 12t, 2 bytes
.j2848\@:
	jr .j2849\@ ; 12t, 2 bytes
.j2849\@:
	jr .j2850\@ ; 12t, 2 bytes
.j2850\@:
	jr .j2851\@ ; 12t, 2 bytes
.j2851\@:
	jr .j2852\@ ; 12t, 2 bytes
.j2852\@:
	jr .j2853\@ ; 12t, 2 bytes
.j2853\@:
	jr .j2854\@ ; 12t, 2 bytes
.j2854\@:
	jr .j2855\@ ; 12t, 2 bytes
.j2855\@:
	jr .j2856\@ ; 12t, 2 bytes
.j2856\@:
	jr .j2857\@ ; 12t, 2 bytes
.j2857\@:
	jr .j2858\@ ; 12t, 2 bytes
.j2858\@:
	jr .j2859\@ ; 12t, 2 bytes
.j2859\@:
	jr .j2860\@ ; 12t, 2 bytes
.j2860\@:
	jr .j2861\@ ; 12t, 2 bytes
.j2861\@:
	ENDM

sleep_273 MACRO
	or 0
	or 0
	or 0
	jr .j2862\@ ; 12t, 2 bytes
.j2862\@:
	jr .j2863\@ ; 12t, 2 bytes
.j2863\@:
	jr .j2864\@ ; 12t, 2 bytes
.j2864\@:
	jr .j2865\@ ; 12t, 2 bytes
.j2865\@:
	jr .j2866\@ ; 12t, 2 bytes
.j2866\@:
	jr .j2867\@ ; 12t, 2 bytes
.j2867\@:
	jr .j2868\@ ; 12t, 2 bytes
.j2868\@:
	jr .j2869\@ ; 12t, 2 bytes
.j2869\@:
	jr .j2870\@ ; 12t, 2 bytes
.j2870\@:
	jr .j2871\@ ; 12t, 2 bytes
.j2871\@:
	jr .j2872\@ ; 12t, 2 bytes
.j2872\@:
	jr .j2873\@ ; 12t, 2 bytes
.j2873\@:
	jr .j2874\@ ; 12t, 2 bytes
.j2874\@:
	jr .j2875\@ ; 12t, 2 bytes
.j2875\@:
	jr .j2876\@ ; 12t, 2 bytes
.j2876\@:
	jr .j2877\@ ; 12t, 2 bytes
.j2877\@:
	jr .j2878\@ ; 12t, 2 bytes
.j2878\@:
	jr .j2879\@ ; 12t, 2 bytes
.j2879\@:
	jr .j2880\@ ; 12t, 2 bytes
.j2880\@:
	jr .j2881\@ ; 12t, 2 bytes
.j2881\@:
	jr .j2882\@ ; 12t, 2 bytes
.j2882\@:
	ENDM

sleep_274 MACRO
	jp .j2883\@ ; 10t, 3 bytes
.j2883\@:
	jr .j2884\@ ; 12t, 2 bytes
.j2884\@:
	jr .j2885\@ ; 12t, 2 bytes
.j2885\@:
	jr .j2886\@ ; 12t, 2 bytes
.j2886\@:
	jr .j2887\@ ; 12t, 2 bytes
.j2887\@:
	jr .j2888\@ ; 12t, 2 bytes
.j2888\@:
	jr .j2889\@ ; 12t, 2 bytes
.j2889\@:
	jr .j2890\@ ; 12t, 2 bytes
.j2890\@:
	jr .j2891\@ ; 12t, 2 bytes
.j2891\@:
	jr .j2892\@ ; 12t, 2 bytes
.j2892\@:
	jr .j2893\@ ; 12t, 2 bytes
.j2893\@:
	jr .j2894\@ ; 12t, 2 bytes
.j2894\@:
	jr .j2895\@ ; 12t, 2 bytes
.j2895\@:
	jr .j2896\@ ; 12t, 2 bytes
.j2896\@:
	jr .j2897\@ ; 12t, 2 bytes
.j2897\@:
	jr .j2898\@ ; 12t, 2 bytes
.j2898\@:
	jr .j2899\@ ; 12t, 2 bytes
.j2899\@:
	jr .j2900\@ ; 12t, 2 bytes
.j2900\@:
	jr .j2901\@ ; 12t, 2 bytes
.j2901\@:
	jr .j2902\@ ; 12t, 2 bytes
.j2902\@:
	jr .j2903\@ ; 12t, 2 bytes
.j2903\@:
	jr .j2904\@ ; 12t, 2 bytes
.j2904\@:
	jr .j2905\@ ; 12t, 2 bytes
.j2905\@:
	ENDM

sleep_275 MACRO
	nop
	or 0
	jr .j2906\@ ; 12t, 2 bytes
.j2906\@:
	jr .j2907\@ ; 12t, 2 bytes
.j2907\@:
	jr .j2908\@ ; 12t, 2 bytes
.j2908\@:
	jr .j2909\@ ; 12t, 2 bytes
.j2909\@:
	jr .j2910\@ ; 12t, 2 bytes
.j2910\@:
	jr .j2911\@ ; 12t, 2 bytes
.j2911\@:
	jr .j2912\@ ; 12t, 2 bytes
.j2912\@:
	jr .j2913\@ ; 12t, 2 bytes
.j2913\@:
	jr .j2914\@ ; 12t, 2 bytes
.j2914\@:
	jr .j2915\@ ; 12t, 2 bytes
.j2915\@:
	jr .j2916\@ ; 12t, 2 bytes
.j2916\@:
	jr .j2917\@ ; 12t, 2 bytes
.j2917\@:
	jr .j2918\@ ; 12t, 2 bytes
.j2918\@:
	jr .j2919\@ ; 12t, 2 bytes
.j2919\@:
	jr .j2920\@ ; 12t, 2 bytes
.j2920\@:
	jr .j2921\@ ; 12t, 2 bytes
.j2921\@:
	jr .j2922\@ ; 12t, 2 bytes
.j2922\@:
	jr .j2923\@ ; 12t, 2 bytes
.j2923\@:
	jr .j2924\@ ; 12t, 2 bytes
.j2924\@:
	jr .j2925\@ ; 12t, 2 bytes
.j2925\@:
	jr .j2926\@ ; 12t, 2 bytes
.j2926\@:
	jr .j2927\@ ; 12t, 2 bytes
.j2927\@:
	ENDM

sleep_276 MACRO
	jr .j2928\@ ; 12t, 2 bytes
.j2928\@:
	jr .j2929\@ ; 12t, 2 bytes
.j2929\@:
	jr .j2930\@ ; 12t, 2 bytes
.j2930\@:
	jr .j2931\@ ; 12t, 2 bytes
.j2931\@:
	jr .j2932\@ ; 12t, 2 bytes
.j2932\@:
	jr .j2933\@ ; 12t, 2 bytes
.j2933\@:
	jr .j2934\@ ; 12t, 2 bytes
.j2934\@:
	jr .j2935\@ ; 12t, 2 bytes
.j2935\@:
	jr .j2936\@ ; 12t, 2 bytes
.j2936\@:
	jr .j2937\@ ; 12t, 2 bytes
.j2937\@:
	jr .j2938\@ ; 12t, 2 bytes
.j2938\@:
	jr .j2939\@ ; 12t, 2 bytes
.j2939\@:
	jr .j2940\@ ; 12t, 2 bytes
.j2940\@:
	jr .j2941\@ ; 12t, 2 bytes
.j2941\@:
	jr .j2942\@ ; 12t, 2 bytes
.j2942\@:
	jr .j2943\@ ; 12t, 2 bytes
.j2943\@:
	jr .j2944\@ ; 12t, 2 bytes
.j2944\@:
	jr .j2945\@ ; 12t, 2 bytes
.j2945\@:
	jr .j2946\@ ; 12t, 2 bytes
.j2946\@:
	jr .j2947\@ ; 12t, 2 bytes
.j2947\@:
	jr .j2948\@ ; 12t, 2 bytes
.j2948\@:
	jr .j2949\@ ; 12t, 2 bytes
.j2949\@:
	jr .j2950\@ ; 12t, 2 bytes
.j2950\@:
	ENDM

sleep_277 MACRO
	nop
	or 0
	or 0
	or 0
	jr .j2951\@ ; 12t, 2 bytes
.j2951\@:
	jr .j2952\@ ; 12t, 2 bytes
.j2952\@:
	jr .j2953\@ ; 12t, 2 bytes
.j2953\@:
	jr .j2954\@ ; 12t, 2 bytes
.j2954\@:
	jr .j2955\@ ; 12t, 2 bytes
.j2955\@:
	jr .j2956\@ ; 12t, 2 bytes
.j2956\@:
	jr .j2957\@ ; 12t, 2 bytes
.j2957\@:
	jr .j2958\@ ; 12t, 2 bytes
.j2958\@:
	jr .j2959\@ ; 12t, 2 bytes
.j2959\@:
	jr .j2960\@ ; 12t, 2 bytes
.j2960\@:
	jr .j2961\@ ; 12t, 2 bytes
.j2961\@:
	jr .j2962\@ ; 12t, 2 bytes
.j2962\@:
	jr .j2963\@ ; 12t, 2 bytes
.j2963\@:
	jr .j2964\@ ; 12t, 2 bytes
.j2964\@:
	jr .j2965\@ ; 12t, 2 bytes
.j2965\@:
	jr .j2966\@ ; 12t, 2 bytes
.j2966\@:
	jr .j2967\@ ; 12t, 2 bytes
.j2967\@:
	jr .j2968\@ ; 12t, 2 bytes
.j2968\@:
	jr .j2969\@ ; 12t, 2 bytes
.j2969\@:
	jr .j2970\@ ; 12t, 2 bytes
.j2970\@:
	jr .j2971\@ ; 12t, 2 bytes
.j2971\@:
	ENDM

sleep_278 MACRO
	or 0
	or 0
	jr .j2972\@ ; 12t, 2 bytes
.j2972\@:
	jr .j2973\@ ; 12t, 2 bytes
.j2973\@:
	jr .j2974\@ ; 12t, 2 bytes
.j2974\@:
	jr .j2975\@ ; 12t, 2 bytes
.j2975\@:
	jr .j2976\@ ; 12t, 2 bytes
.j2976\@:
	jr .j2977\@ ; 12t, 2 bytes
.j2977\@:
	jr .j2978\@ ; 12t, 2 bytes
.j2978\@:
	jr .j2979\@ ; 12t, 2 bytes
.j2979\@:
	jr .j2980\@ ; 12t, 2 bytes
.j2980\@:
	jr .j2981\@ ; 12t, 2 bytes
.j2981\@:
	jr .j2982\@ ; 12t, 2 bytes
.j2982\@:
	jr .j2983\@ ; 12t, 2 bytes
.j2983\@:
	jr .j2984\@ ; 12t, 2 bytes
.j2984\@:
	jr .j2985\@ ; 12t, 2 bytes
.j2985\@:
	jr .j2986\@ ; 12t, 2 bytes
.j2986\@:
	jr .j2987\@ ; 12t, 2 bytes
.j2987\@:
	jr .j2988\@ ; 12t, 2 bytes
.j2988\@:
	jr .j2989\@ ; 12t, 2 bytes
.j2989\@:
	jr .j2990\@ ; 12t, 2 bytes
.j2990\@:
	jr .j2991\@ ; 12t, 2 bytes
.j2991\@:
	jr .j2992\@ ; 12t, 2 bytes
.j2992\@:
	jr .j2993\@ ; 12t, 2 bytes
.j2993\@:
	ENDM

sleep_279 MACRO
	nop
	nop
	or 0
	jr .j2994\@ ; 12t, 2 bytes
.j2994\@:
	jr .j2995\@ ; 12t, 2 bytes
.j2995\@:
	jr .j2996\@ ; 12t, 2 bytes
.j2996\@:
	jr .j2997\@ ; 12t, 2 bytes
.j2997\@:
	jr .j2998\@ ; 12t, 2 bytes
.j2998\@:
	jr .j2999\@ ; 12t, 2 bytes
.j2999\@:
	jr .j3000\@ ; 12t, 2 bytes
.j3000\@:
	jr .j3001\@ ; 12t, 2 bytes
.j3001\@:
	jr .j3002\@ ; 12t, 2 bytes
.j3002\@:
	jr .j3003\@ ; 12t, 2 bytes
.j3003\@:
	jr .j3004\@ ; 12t, 2 bytes
.j3004\@:
	jr .j3005\@ ; 12t, 2 bytes
.j3005\@:
	jr .j3006\@ ; 12t, 2 bytes
.j3006\@:
	jr .j3007\@ ; 12t, 2 bytes
.j3007\@:
	jr .j3008\@ ; 12t, 2 bytes
.j3008\@:
	jr .j3009\@ ; 12t, 2 bytes
.j3009\@:
	jr .j3010\@ ; 12t, 2 bytes
.j3010\@:
	jr .j3011\@ ; 12t, 2 bytes
.j3011\@:
	jr .j3012\@ ; 12t, 2 bytes
.j3012\@:
	jr .j3013\@ ; 12t, 2 bytes
.j3013\@:
	jr .j3014\@ ; 12t, 2 bytes
.j3014\@:
	jr .j3015\@ ; 12t, 2 bytes
.j3015\@:
	ENDM

sleep_280 MACRO
	nop
	jr .j3016\@ ; 12t, 2 bytes
.j3016\@:
	jr .j3017\@ ; 12t, 2 bytes
.j3017\@:
	jr .j3018\@ ; 12t, 2 bytes
.j3018\@:
	jr .j3019\@ ; 12t, 2 bytes
.j3019\@:
	jr .j3020\@ ; 12t, 2 bytes
.j3020\@:
	jr .j3021\@ ; 12t, 2 bytes
.j3021\@:
	jr .j3022\@ ; 12t, 2 bytes
.j3022\@:
	jr .j3023\@ ; 12t, 2 bytes
.j3023\@:
	jr .j3024\@ ; 12t, 2 bytes
.j3024\@:
	jr .j3025\@ ; 12t, 2 bytes
.j3025\@:
	jr .j3026\@ ; 12t, 2 bytes
.j3026\@:
	jr .j3027\@ ; 12t, 2 bytes
.j3027\@:
	jr .j3028\@ ; 12t, 2 bytes
.j3028\@:
	jr .j3029\@ ; 12t, 2 bytes
.j3029\@:
	jr .j3030\@ ; 12t, 2 bytes
.j3030\@:
	jr .j3031\@ ; 12t, 2 bytes
.j3031\@:
	jr .j3032\@ ; 12t, 2 bytes
.j3032\@:
	jr .j3033\@ ; 12t, 2 bytes
.j3033\@:
	jr .j3034\@ ; 12t, 2 bytes
.j3034\@:
	jr .j3035\@ ; 12t, 2 bytes
.j3035\@:
	jr .j3036\@ ; 12t, 2 bytes
.j3036\@:
	jr .j3037\@ ; 12t, 2 bytes
.j3037\@:
	jr .j3038\@ ; 12t, 2 bytes
.j3038\@:
	ENDM

sleep_281 MACRO
	or 0
	jp .j3039\@ ; 10t, 3 bytes
.j3039\@:
	jr .j3040\@ ; 12t, 2 bytes
.j3040\@:
	jr .j3041\@ ; 12t, 2 bytes
.j3041\@:
	jr .j3042\@ ; 12t, 2 bytes
.j3042\@:
	jr .j3043\@ ; 12t, 2 bytes
.j3043\@:
	jr .j3044\@ ; 12t, 2 bytes
.j3044\@:
	jr .j3045\@ ; 12t, 2 bytes
.j3045\@:
	jr .j3046\@ ; 12t, 2 bytes
.j3046\@:
	jr .j3047\@ ; 12t, 2 bytes
.j3047\@:
	jr .j3048\@ ; 12t, 2 bytes
.j3048\@:
	jr .j3049\@ ; 12t, 2 bytes
.j3049\@:
	jr .j3050\@ ; 12t, 2 bytes
.j3050\@:
	jr .j3051\@ ; 12t, 2 bytes
.j3051\@:
	jr .j3052\@ ; 12t, 2 bytes
.j3052\@:
	jr .j3053\@ ; 12t, 2 bytes
.j3053\@:
	jr .j3054\@ ; 12t, 2 bytes
.j3054\@:
	jr .j3055\@ ; 12t, 2 bytes
.j3055\@:
	jr .j3056\@ ; 12t, 2 bytes
.j3056\@:
	jr .j3057\@ ; 12t, 2 bytes
.j3057\@:
	jr .j3058\@ ; 12t, 2 bytes
.j3058\@:
	jr .j3059\@ ; 12t, 2 bytes
.j3059\@:
	jr .j3060\@ ; 12t, 2 bytes
.j3060\@:
	jr .j3061\@ ; 12t, 2 bytes
.j3061\@:
	ENDM

sleep_282 MACRO
	nop
	or 0
	or 0
	jr .j3062\@ ; 12t, 2 bytes
.j3062\@:
	jr .j3063\@ ; 12t, 2 bytes
.j3063\@:
	jr .j3064\@ ; 12t, 2 bytes
.j3064\@:
	jr .j3065\@ ; 12t, 2 bytes
.j3065\@:
	jr .j3066\@ ; 12t, 2 bytes
.j3066\@:
	jr .j3067\@ ; 12t, 2 bytes
.j3067\@:
	jr .j3068\@ ; 12t, 2 bytes
.j3068\@:
	jr .j3069\@ ; 12t, 2 bytes
.j3069\@:
	jr .j3070\@ ; 12t, 2 bytes
.j3070\@:
	jr .j3071\@ ; 12t, 2 bytes
.j3071\@:
	jr .j3072\@ ; 12t, 2 bytes
.j3072\@:
	jr .j3073\@ ; 12t, 2 bytes
.j3073\@:
	jr .j3074\@ ; 12t, 2 bytes
.j3074\@:
	jr .j3075\@ ; 12t, 2 bytes
.j3075\@:
	jr .j3076\@ ; 12t, 2 bytes
.j3076\@:
	jr .j3077\@ ; 12t, 2 bytes
.j3077\@:
	jr .j3078\@ ; 12t, 2 bytes
.j3078\@:
	jr .j3079\@ ; 12t, 2 bytes
.j3079\@:
	jr .j3080\@ ; 12t, 2 bytes
.j3080\@:
	jr .j3081\@ ; 12t, 2 bytes
.j3081\@:
	jr .j3082\@ ; 12t, 2 bytes
.j3082\@:
	jr .j3083\@ ; 12t, 2 bytes
.j3083\@:
	ENDM

sleep_283 MACRO
	or 0
	jr .j3084\@ ; 12t, 2 bytes
.j3084\@:
	jr .j3085\@ ; 12t, 2 bytes
.j3085\@:
	jr .j3086\@ ; 12t, 2 bytes
.j3086\@:
	jr .j3087\@ ; 12t, 2 bytes
.j3087\@:
	jr .j3088\@ ; 12t, 2 bytes
.j3088\@:
	jr .j3089\@ ; 12t, 2 bytes
.j3089\@:
	jr .j3090\@ ; 12t, 2 bytes
.j3090\@:
	jr .j3091\@ ; 12t, 2 bytes
.j3091\@:
	jr .j3092\@ ; 12t, 2 bytes
.j3092\@:
	jr .j3093\@ ; 12t, 2 bytes
.j3093\@:
	jr .j3094\@ ; 12t, 2 bytes
.j3094\@:
	jr .j3095\@ ; 12t, 2 bytes
.j3095\@:
	jr .j3096\@ ; 12t, 2 bytes
.j3096\@:
	jr .j3097\@ ; 12t, 2 bytes
.j3097\@:
	jr .j3098\@ ; 12t, 2 bytes
.j3098\@:
	jr .j3099\@ ; 12t, 2 bytes
.j3099\@:
	jr .j3100\@ ; 12t, 2 bytes
.j3100\@:
	jr .j3101\@ ; 12t, 2 bytes
.j3101\@:
	jr .j3102\@ ; 12t, 2 bytes
.j3102\@:
	jr .j3103\@ ; 12t, 2 bytes
.j3103\@:
	jr .j3104\@ ; 12t, 2 bytes
.j3104\@:
	jr .j3105\@ ; 12t, 2 bytes
.j3105\@:
	jr .j3106\@ ; 12t, 2 bytes
.j3106\@:
	ENDM

sleep_284 MACRO
	nop
	nop
	jr .j3107\@ ; 12t, 2 bytes
.j3107\@:
	jr .j3108\@ ; 12t, 2 bytes
.j3108\@:
	jr .j3109\@ ; 12t, 2 bytes
.j3109\@:
	jr .j3110\@ ; 12t, 2 bytes
.j3110\@:
	jr .j3111\@ ; 12t, 2 bytes
.j3111\@:
	jr .j3112\@ ; 12t, 2 bytes
.j3112\@:
	jr .j3113\@ ; 12t, 2 bytes
.j3113\@:
	jr .j3114\@ ; 12t, 2 bytes
.j3114\@:
	jr .j3115\@ ; 12t, 2 bytes
.j3115\@:
	jr .j3116\@ ; 12t, 2 bytes
.j3116\@:
	jr .j3117\@ ; 12t, 2 bytes
.j3117\@:
	jr .j3118\@ ; 12t, 2 bytes
.j3118\@:
	jr .j3119\@ ; 12t, 2 bytes
.j3119\@:
	jr .j3120\@ ; 12t, 2 bytes
.j3120\@:
	jr .j3121\@ ; 12t, 2 bytes
.j3121\@:
	jr .j3122\@ ; 12t, 2 bytes
.j3122\@:
	jr .j3123\@ ; 12t, 2 bytes
.j3123\@:
	jr .j3124\@ ; 12t, 2 bytes
.j3124\@:
	jr .j3125\@ ; 12t, 2 bytes
.j3125\@:
	jr .j3126\@ ; 12t, 2 bytes
.j3126\@:
	jr .j3127\@ ; 12t, 2 bytes
.j3127\@:
	jr .j3128\@ ; 12t, 2 bytes
.j3128\@:
	jr .j3129\@ ; 12t, 2 bytes
.j3129\@:
	ENDM

sleep_285 MACRO
	or 0
	or 0
	or 0
	jr .j3130\@ ; 12t, 2 bytes
.j3130\@:
	jr .j3131\@ ; 12t, 2 bytes
.j3131\@:
	jr .j3132\@ ; 12t, 2 bytes
.j3132\@:
	jr .j3133\@ ; 12t, 2 bytes
.j3133\@:
	jr .j3134\@ ; 12t, 2 bytes
.j3134\@:
	jr .j3135\@ ; 12t, 2 bytes
.j3135\@:
	jr .j3136\@ ; 12t, 2 bytes
.j3136\@:
	jr .j3137\@ ; 12t, 2 bytes
.j3137\@:
	jr .j3138\@ ; 12t, 2 bytes
.j3138\@:
	jr .j3139\@ ; 12t, 2 bytes
.j3139\@:
	jr .j3140\@ ; 12t, 2 bytes
.j3140\@:
	jr .j3141\@ ; 12t, 2 bytes
.j3141\@:
	jr .j3142\@ ; 12t, 2 bytes
.j3142\@:
	jr .j3143\@ ; 12t, 2 bytes
.j3143\@:
	jr .j3144\@ ; 12t, 2 bytes
.j3144\@:
	jr .j3145\@ ; 12t, 2 bytes
.j3145\@:
	jr .j3146\@ ; 12t, 2 bytes
.j3146\@:
	jr .j3147\@ ; 12t, 2 bytes
.j3147\@:
	jr .j3148\@ ; 12t, 2 bytes
.j3148\@:
	jr .j3149\@ ; 12t, 2 bytes
.j3149\@:
	jr .j3150\@ ; 12t, 2 bytes
.j3150\@:
	jr .j3151\@ ; 12t, 2 bytes
.j3151\@:
	ENDM

sleep_286 MACRO
	jp .j3152\@ ; 10t, 3 bytes
.j3152\@:
	jr .j3153\@ ; 12t, 2 bytes
.j3153\@:
	jr .j3154\@ ; 12t, 2 bytes
.j3154\@:
	jr .j3155\@ ; 12t, 2 bytes
.j3155\@:
	jr .j3156\@ ; 12t, 2 bytes
.j3156\@:
	jr .j3157\@ ; 12t, 2 bytes
.j3157\@:
	jr .j3158\@ ; 12t, 2 bytes
.j3158\@:
	jr .j3159\@ ; 12t, 2 bytes
.j3159\@:
	jr .j3160\@ ; 12t, 2 bytes
.j3160\@:
	jr .j3161\@ ; 12t, 2 bytes
.j3161\@:
	jr .j3162\@ ; 12t, 2 bytes
.j3162\@:
	jr .j3163\@ ; 12t, 2 bytes
.j3163\@:
	jr .j3164\@ ; 12t, 2 bytes
.j3164\@:
	jr .j3165\@ ; 12t, 2 bytes
.j3165\@:
	jr .j3166\@ ; 12t, 2 bytes
.j3166\@:
	jr .j3167\@ ; 12t, 2 bytes
.j3167\@:
	jr .j3168\@ ; 12t, 2 bytes
.j3168\@:
	jr .j3169\@ ; 12t, 2 bytes
.j3169\@:
	jr .j3170\@ ; 12t, 2 bytes
.j3170\@:
	jr .j3171\@ ; 12t, 2 bytes
.j3171\@:
	jr .j3172\@ ; 12t, 2 bytes
.j3172\@:
	jr .j3173\@ ; 12t, 2 bytes
.j3173\@:
	jr .j3174\@ ; 12t, 2 bytes
.j3174\@:
	jr .j3175\@ ; 12t, 2 bytes
.j3175\@:
	ENDM

sleep_287 MACRO
	nop
	or 0
	jr .j3176\@ ; 12t, 2 bytes
.j3176\@:
	jr .j3177\@ ; 12t, 2 bytes
.j3177\@:
	jr .j3178\@ ; 12t, 2 bytes
.j3178\@:
	jr .j3179\@ ; 12t, 2 bytes
.j3179\@:
	jr .j3180\@ ; 12t, 2 bytes
.j3180\@:
	jr .j3181\@ ; 12t, 2 bytes
.j3181\@:
	jr .j3182\@ ; 12t, 2 bytes
.j3182\@:
	jr .j3183\@ ; 12t, 2 bytes
.j3183\@:
	jr .j3184\@ ; 12t, 2 bytes
.j3184\@:
	jr .j3185\@ ; 12t, 2 bytes
.j3185\@:
	jr .j3186\@ ; 12t, 2 bytes
.j3186\@:
	jr .j3187\@ ; 12t, 2 bytes
.j3187\@:
	jr .j3188\@ ; 12t, 2 bytes
.j3188\@:
	jr .j3189\@ ; 12t, 2 bytes
.j3189\@:
	jr .j3190\@ ; 12t, 2 bytes
.j3190\@:
	jr .j3191\@ ; 12t, 2 bytes
.j3191\@:
	jr .j3192\@ ; 12t, 2 bytes
.j3192\@:
	jr .j3193\@ ; 12t, 2 bytes
.j3193\@:
	jr .j3194\@ ; 12t, 2 bytes
.j3194\@:
	jr .j3195\@ ; 12t, 2 bytes
.j3195\@:
	jr .j3196\@ ; 12t, 2 bytes
.j3196\@:
	jr .j3197\@ ; 12t, 2 bytes
.j3197\@:
	jr .j3198\@ ; 12t, 2 bytes
.j3198\@:
	ENDM

sleep_288 MACRO
	jr .j3199\@ ; 12t, 2 bytes
.j3199\@:
	jr .j3200\@ ; 12t, 2 bytes
.j3200\@:
	jr .j3201\@ ; 12t, 2 bytes
.j3201\@:
	jr .j3202\@ ; 12t, 2 bytes
.j3202\@:
	jr .j3203\@ ; 12t, 2 bytes
.j3203\@:
	jr .j3204\@ ; 12t, 2 bytes
.j3204\@:
	jr .j3205\@ ; 12t, 2 bytes
.j3205\@:
	jr .j3206\@ ; 12t, 2 bytes
.j3206\@:
	jr .j3207\@ ; 12t, 2 bytes
.j3207\@:
	jr .j3208\@ ; 12t, 2 bytes
.j3208\@:
	jr .j3209\@ ; 12t, 2 bytes
.j3209\@:
	jr .j3210\@ ; 12t, 2 bytes
.j3210\@:
	jr .j3211\@ ; 12t, 2 bytes
.j3211\@:
	jr .j3212\@ ; 12t, 2 bytes
.j3212\@:
	jr .j3213\@ ; 12t, 2 bytes
.j3213\@:
	jr .j3214\@ ; 12t, 2 bytes
.j3214\@:
	jr .j3215\@ ; 12t, 2 bytes
.j3215\@:
	jr .j3216\@ ; 12t, 2 bytes
.j3216\@:
	jr .j3217\@ ; 12t, 2 bytes
.j3217\@:
	jr .j3218\@ ; 12t, 2 bytes
.j3218\@:
	jr .j3219\@ ; 12t, 2 bytes
.j3219\@:
	jr .j3220\@ ; 12t, 2 bytes
.j3220\@:
	jr .j3221\@ ; 12t, 2 bytes
.j3221\@:
	jr .j3222\@ ; 12t, 2 bytes
.j3222\@:
	ENDM

sleep_289 MACRO
	nop
	or 0
	or 0
	or 0
	jr .j3223\@ ; 12t, 2 bytes
.j3223\@:
	jr .j3224\@ ; 12t, 2 bytes
.j3224\@:
	jr .j3225\@ ; 12t, 2 bytes
.j3225\@:
	jr .j3226\@ ; 12t, 2 bytes
.j3226\@:
	jr .j3227\@ ; 12t, 2 bytes
.j3227\@:
	jr .j3228\@ ; 12t, 2 bytes
.j3228\@:
	jr .j3229\@ ; 12t, 2 bytes
.j3229\@:
	jr .j3230\@ ; 12t, 2 bytes
.j3230\@:
	jr .j3231\@ ; 12t, 2 bytes
.j3231\@:
	jr .j3232\@ ; 12t, 2 bytes
.j3232\@:
	jr .j3233\@ ; 12t, 2 bytes
.j3233\@:
	jr .j3234\@ ; 12t, 2 bytes
.j3234\@:
	jr .j3235\@ ; 12t, 2 bytes
.j3235\@:
	jr .j3236\@ ; 12t, 2 bytes
.j3236\@:
	jr .j3237\@ ; 12t, 2 bytes
.j3237\@:
	jr .j3238\@ ; 12t, 2 bytes
.j3238\@:
	jr .j3239\@ ; 12t, 2 bytes
.j3239\@:
	jr .j3240\@ ; 12t, 2 bytes
.j3240\@:
	jr .j3241\@ ; 12t, 2 bytes
.j3241\@:
	jr .j3242\@ ; 12t, 2 bytes
.j3242\@:
	jr .j3243\@ ; 12t, 2 bytes
.j3243\@:
	jr .j3244\@ ; 12t, 2 bytes
.j3244\@:
	ENDM

sleep_290 MACRO
	or 0
	or 0
	jr .j3245\@ ; 12t, 2 bytes
.j3245\@:
	jr .j3246\@ ; 12t, 2 bytes
.j3246\@:
	jr .j3247\@ ; 12t, 2 bytes
.j3247\@:
	jr .j3248\@ ; 12t, 2 bytes
.j3248\@:
	jr .j3249\@ ; 12t, 2 bytes
.j3249\@:
	jr .j3250\@ ; 12t, 2 bytes
.j3250\@:
	jr .j3251\@ ; 12t, 2 bytes
.j3251\@:
	jr .j3252\@ ; 12t, 2 bytes
.j3252\@:
	jr .j3253\@ ; 12t, 2 bytes
.j3253\@:
	jr .j3254\@ ; 12t, 2 bytes
.j3254\@:
	jr .j3255\@ ; 12t, 2 bytes
.j3255\@:
	jr .j3256\@ ; 12t, 2 bytes
.j3256\@:
	jr .j3257\@ ; 12t, 2 bytes
.j3257\@:
	jr .j3258\@ ; 12t, 2 bytes
.j3258\@:
	jr .j3259\@ ; 12t, 2 bytes
.j3259\@:
	jr .j3260\@ ; 12t, 2 bytes
.j3260\@:
	jr .j3261\@ ; 12t, 2 bytes
.j3261\@:
	jr .j3262\@ ; 12t, 2 bytes
.j3262\@:
	jr .j3263\@ ; 12t, 2 bytes
.j3263\@:
	jr .j3264\@ ; 12t, 2 bytes
.j3264\@:
	jr .j3265\@ ; 12t, 2 bytes
.j3265\@:
	jr .j3266\@ ; 12t, 2 bytes
.j3266\@:
	jr .j3267\@ ; 12t, 2 bytes
.j3267\@:
	ENDM

sleep_291 MACRO
	nop
	nop
	or 0
	jr .j3268\@ ; 12t, 2 bytes
.j3268\@:
	jr .j3269\@ ; 12t, 2 bytes
.j3269\@:
	jr .j3270\@ ; 12t, 2 bytes
.j3270\@:
	jr .j3271\@ ; 12t, 2 bytes
.j3271\@:
	jr .j3272\@ ; 12t, 2 bytes
.j3272\@:
	jr .j3273\@ ; 12t, 2 bytes
.j3273\@:
	jr .j3274\@ ; 12t, 2 bytes
.j3274\@:
	jr .j3275\@ ; 12t, 2 bytes
.j3275\@:
	jr .j3276\@ ; 12t, 2 bytes
.j3276\@:
	jr .j3277\@ ; 12t, 2 bytes
.j3277\@:
	jr .j3278\@ ; 12t, 2 bytes
.j3278\@:
	jr .j3279\@ ; 12t, 2 bytes
.j3279\@:
	jr .j3280\@ ; 12t, 2 bytes
.j3280\@:
	jr .j3281\@ ; 12t, 2 bytes
.j3281\@:
	jr .j3282\@ ; 12t, 2 bytes
.j3282\@:
	jr .j3283\@ ; 12t, 2 bytes
.j3283\@:
	jr .j3284\@ ; 12t, 2 bytes
.j3284\@:
	jr .j3285\@ ; 12t, 2 bytes
.j3285\@:
	jr .j3286\@ ; 12t, 2 bytes
.j3286\@:
	jr .j3287\@ ; 12t, 2 bytes
.j3287\@:
	jr .j3288\@ ; 12t, 2 bytes
.j3288\@:
	jr .j3289\@ ; 12t, 2 bytes
.j3289\@:
	jr .j3290\@ ; 12t, 2 bytes
.j3290\@:
	ENDM

sleep_292 MACRO
	nop
	jr .j3291\@ ; 12t, 2 bytes
.j3291\@:
	jr .j3292\@ ; 12t, 2 bytes
.j3292\@:
	jr .j3293\@ ; 12t, 2 bytes
.j3293\@:
	jr .j3294\@ ; 12t, 2 bytes
.j3294\@:
	jr .j3295\@ ; 12t, 2 bytes
.j3295\@:
	jr .j3296\@ ; 12t, 2 bytes
.j3296\@:
	jr .j3297\@ ; 12t, 2 bytes
.j3297\@:
	jr .j3298\@ ; 12t, 2 bytes
.j3298\@:
	jr .j3299\@ ; 12t, 2 bytes
.j3299\@:
	jr .j3300\@ ; 12t, 2 bytes
.j3300\@:
	jr .j3301\@ ; 12t, 2 bytes
.j3301\@:
	jr .j3302\@ ; 12t, 2 bytes
.j3302\@:
	jr .j3303\@ ; 12t, 2 bytes
.j3303\@:
	jr .j3304\@ ; 12t, 2 bytes
.j3304\@:
	jr .j3305\@ ; 12t, 2 bytes
.j3305\@:
	jr .j3306\@ ; 12t, 2 bytes
.j3306\@:
	jr .j3307\@ ; 12t, 2 bytes
.j3307\@:
	jr .j3308\@ ; 12t, 2 bytes
.j3308\@:
	jr .j3309\@ ; 12t, 2 bytes
.j3309\@:
	jr .j3310\@ ; 12t, 2 bytes
.j3310\@:
	jr .j3311\@ ; 12t, 2 bytes
.j3311\@:
	jr .j3312\@ ; 12t, 2 bytes
.j3312\@:
	jr .j3313\@ ; 12t, 2 bytes
.j3313\@:
	jr .j3314\@ ; 12t, 2 bytes
.j3314\@:
	ENDM

sleep_293 MACRO
	or 0
	jp .j3315\@ ; 10t, 3 bytes
.j3315\@:
	jr .j3316\@ ; 12t, 2 bytes
.j3316\@:
	jr .j3317\@ ; 12t, 2 bytes
.j3317\@:
	jr .j3318\@ ; 12t, 2 bytes
.j3318\@:
	jr .j3319\@ ; 12t, 2 bytes
.j3319\@:
	jr .j3320\@ ; 12t, 2 bytes
.j3320\@:
	jr .j3321\@ ; 12t, 2 bytes
.j3321\@:
	jr .j3322\@ ; 12t, 2 bytes
.j3322\@:
	jr .j3323\@ ; 12t, 2 bytes
.j3323\@:
	jr .j3324\@ ; 12t, 2 bytes
.j3324\@:
	jr .j3325\@ ; 12t, 2 bytes
.j3325\@:
	jr .j3326\@ ; 12t, 2 bytes
.j3326\@:
	jr .j3327\@ ; 12t, 2 bytes
.j3327\@:
	jr .j3328\@ ; 12t, 2 bytes
.j3328\@:
	jr .j3329\@ ; 12t, 2 bytes
.j3329\@:
	jr .j3330\@ ; 12t, 2 bytes
.j3330\@:
	jr .j3331\@ ; 12t, 2 bytes
.j3331\@:
	jr .j3332\@ ; 12t, 2 bytes
.j3332\@:
	jr .j3333\@ ; 12t, 2 bytes
.j3333\@:
	jr .j3334\@ ; 12t, 2 bytes
.j3334\@:
	jr .j3335\@ ; 12t, 2 bytes
.j3335\@:
	jr .j3336\@ ; 12t, 2 bytes
.j3336\@:
	jr .j3337\@ ; 12t, 2 bytes
.j3337\@:
	jr .j3338\@ ; 12t, 2 bytes
.j3338\@:
	ENDM

sleep_294 MACRO
	nop
	or 0
	or 0
	jr .j3339\@ ; 12t, 2 bytes
.j3339\@:
	jr .j3340\@ ; 12t, 2 bytes
.j3340\@:
	jr .j3341\@ ; 12t, 2 bytes
.j3341\@:
	jr .j3342\@ ; 12t, 2 bytes
.j3342\@:
	jr .j3343\@ ; 12t, 2 bytes
.j3343\@:
	jr .j3344\@ ; 12t, 2 bytes
.j3344\@:
	jr .j3345\@ ; 12t, 2 bytes
.j3345\@:
	jr .j3346\@ ; 12t, 2 bytes
.j3346\@:
	jr .j3347\@ ; 12t, 2 bytes
.j3347\@:
	jr .j3348\@ ; 12t, 2 bytes
.j3348\@:
	jr .j3349\@ ; 12t, 2 bytes
.j3349\@:
	jr .j3350\@ ; 12t, 2 bytes
.j3350\@:
	jr .j3351\@ ; 12t, 2 bytes
.j3351\@:
	jr .j3352\@ ; 12t, 2 bytes
.j3352\@:
	jr .j3353\@ ; 12t, 2 bytes
.j3353\@:
	jr .j3354\@ ; 12t, 2 bytes
.j3354\@:
	jr .j3355\@ ; 12t, 2 bytes
.j3355\@:
	jr .j3356\@ ; 12t, 2 bytes
.j3356\@:
	jr .j3357\@ ; 12t, 2 bytes
.j3357\@:
	jr .j3358\@ ; 12t, 2 bytes
.j3358\@:
	jr .j3359\@ ; 12t, 2 bytes
.j3359\@:
	jr .j3360\@ ; 12t, 2 bytes
.j3360\@:
	jr .j3361\@ ; 12t, 2 bytes
.j3361\@:
	ENDM

sleep_295 MACRO
	or 0
	jr .j3362\@ ; 12t, 2 bytes
.j3362\@:
	jr .j3363\@ ; 12t, 2 bytes
.j3363\@:
	jr .j3364\@ ; 12t, 2 bytes
.j3364\@:
	jr .j3365\@ ; 12t, 2 bytes
.j3365\@:
	jr .j3366\@ ; 12t, 2 bytes
.j3366\@:
	jr .j3367\@ ; 12t, 2 bytes
.j3367\@:
	jr .j3368\@ ; 12t, 2 bytes
.j3368\@:
	jr .j3369\@ ; 12t, 2 bytes
.j3369\@:
	jr .j3370\@ ; 12t, 2 bytes
.j3370\@:
	jr .j3371\@ ; 12t, 2 bytes
.j3371\@:
	jr .j3372\@ ; 12t, 2 bytes
.j3372\@:
	jr .j3373\@ ; 12t, 2 bytes
.j3373\@:
	jr .j3374\@ ; 12t, 2 bytes
.j3374\@:
	jr .j3375\@ ; 12t, 2 bytes
.j3375\@:
	jr .j3376\@ ; 12t, 2 bytes
.j3376\@:
	jr .j3377\@ ; 12t, 2 bytes
.j3377\@:
	jr .j3378\@ ; 12t, 2 bytes
.j3378\@:
	jr .j3379\@ ; 12t, 2 bytes
.j3379\@:
	jr .j3380\@ ; 12t, 2 bytes
.j3380\@:
	jr .j3381\@ ; 12t, 2 bytes
.j3381\@:
	jr .j3382\@ ; 12t, 2 bytes
.j3382\@:
	jr .j3383\@ ; 12t, 2 bytes
.j3383\@:
	jr .j3384\@ ; 12t, 2 bytes
.j3384\@:
	jr .j3385\@ ; 12t, 2 bytes
.j3385\@:
	ENDM

sleep_296 MACRO
	nop
	nop
	jr .j3386\@ ; 12t, 2 bytes
.j3386\@:
	jr .j3387\@ ; 12t, 2 bytes
.j3387\@:
	jr .j3388\@ ; 12t, 2 bytes
.j3388\@:
	jr .j3389\@ ; 12t, 2 bytes
.j3389\@:
	jr .j3390\@ ; 12t, 2 bytes
.j3390\@:
	jr .j3391\@ ; 12t, 2 bytes
.j3391\@:
	jr .j3392\@ ; 12t, 2 bytes
.j3392\@:
	jr .j3393\@ ; 12t, 2 bytes
.j3393\@:
	jr .j3394\@ ; 12t, 2 bytes
.j3394\@:
	jr .j3395\@ ; 12t, 2 bytes
.j3395\@:
	jr .j3396\@ ; 12t, 2 bytes
.j3396\@:
	jr .j3397\@ ; 12t, 2 bytes
.j3397\@:
	jr .j3398\@ ; 12t, 2 bytes
.j3398\@:
	jr .j3399\@ ; 12t, 2 bytes
.j3399\@:
	jr .j3400\@ ; 12t, 2 bytes
.j3400\@:
	jr .j3401\@ ; 12t, 2 bytes
.j3401\@:
	jr .j3402\@ ; 12t, 2 bytes
.j3402\@:
	jr .j3403\@ ; 12t, 2 bytes
.j3403\@:
	jr .j3404\@ ; 12t, 2 bytes
.j3404\@:
	jr .j3405\@ ; 12t, 2 bytes
.j3405\@:
	jr .j3406\@ ; 12t, 2 bytes
.j3406\@:
	jr .j3407\@ ; 12t, 2 bytes
.j3407\@:
	jr .j3408\@ ; 12t, 2 bytes
.j3408\@:
	jr .j3409\@ ; 12t, 2 bytes
.j3409\@:
	ENDM

sleep_297 MACRO
	or 0
	or 0
	or 0
	jr .j3410\@ ; 12t, 2 bytes
.j3410\@:
	jr .j3411\@ ; 12t, 2 bytes
.j3411\@:
	jr .j3412\@ ; 12t, 2 bytes
.j3412\@:
	jr .j3413\@ ; 12t, 2 bytes
.j3413\@:
	jr .j3414\@ ; 12t, 2 bytes
.j3414\@:
	jr .j3415\@ ; 12t, 2 bytes
.j3415\@:
	jr .j3416\@ ; 12t, 2 bytes
.j3416\@:
	jr .j3417\@ ; 12t, 2 bytes
.j3417\@:
	jr .j3418\@ ; 12t, 2 bytes
.j3418\@:
	jr .j3419\@ ; 12t, 2 bytes
.j3419\@:
	jr .j3420\@ ; 12t, 2 bytes
.j3420\@:
	jr .j3421\@ ; 12t, 2 bytes
.j3421\@:
	jr .j3422\@ ; 12t, 2 bytes
.j3422\@:
	jr .j3423\@ ; 12t, 2 bytes
.j3423\@:
	jr .j3424\@ ; 12t, 2 bytes
.j3424\@:
	jr .j3425\@ ; 12t, 2 bytes
.j3425\@:
	jr .j3426\@ ; 12t, 2 bytes
.j3426\@:
	jr .j3427\@ ; 12t, 2 bytes
.j3427\@:
	jr .j3428\@ ; 12t, 2 bytes
.j3428\@:
	jr .j3429\@ ; 12t, 2 bytes
.j3429\@:
	jr .j3430\@ ; 12t, 2 bytes
.j3430\@:
	jr .j3431\@ ; 12t, 2 bytes
.j3431\@:
	jr .j3432\@ ; 12t, 2 bytes
.j3432\@:
	ENDM

sleep_298 MACRO
	jp .j3433\@ ; 10t, 3 bytes
.j3433\@:
	jr .j3434\@ ; 12t, 2 bytes
.j3434\@:
	jr .j3435\@ ; 12t, 2 bytes
.j3435\@:
	jr .j3436\@ ; 12t, 2 bytes
.j3436\@:
	jr .j3437\@ ; 12t, 2 bytes
.j3437\@:
	jr .j3438\@ ; 12t, 2 bytes
.j3438\@:
	jr .j3439\@ ; 12t, 2 bytes
.j3439\@:
	jr .j3440\@ ; 12t, 2 bytes
.j3440\@:
	jr .j3441\@ ; 12t, 2 bytes
.j3441\@:
	jr .j3442\@ ; 12t, 2 bytes
.j3442\@:
	jr .j3443\@ ; 12t, 2 bytes
.j3443\@:
	jr .j3444\@ ; 12t, 2 bytes
.j3444\@:
	jr .j3445\@ ; 12t, 2 bytes
.j3445\@:
	jr .j3446\@ ; 12t, 2 bytes
.j3446\@:
	jr .j3447\@ ; 12t, 2 bytes
.j3447\@:
	jr .j3448\@ ; 12t, 2 bytes
.j3448\@:
	jr .j3449\@ ; 12t, 2 bytes
.j3449\@:
	jr .j3450\@ ; 12t, 2 bytes
.j3450\@:
	jr .j3451\@ ; 12t, 2 bytes
.j3451\@:
	jr .j3452\@ ; 12t, 2 bytes
.j3452\@:
	jr .j3453\@ ; 12t, 2 bytes
.j3453\@:
	jr .j3454\@ ; 12t, 2 bytes
.j3454\@:
	jr .j3455\@ ; 12t, 2 bytes
.j3455\@:
	jr .j3456\@ ; 12t, 2 bytes
.j3456\@:
	jr .j3457\@ ; 12t, 2 bytes
.j3457\@:
	ENDM

sleep_299 MACRO
	nop
	or 0
	jr .j3458\@ ; 12t, 2 bytes
.j3458\@:
	jr .j3459\@ ; 12t, 2 bytes
.j3459\@:
	jr .j3460\@ ; 12t, 2 bytes
.j3460\@:
	jr .j3461\@ ; 12t, 2 bytes
.j3461\@:
	jr .j3462\@ ; 12t, 2 bytes
.j3462\@:
	jr .j3463\@ ; 12t, 2 bytes
.j3463\@:
	jr .j3464\@ ; 12t, 2 bytes
.j3464\@:
	jr .j3465\@ ; 12t, 2 bytes
.j3465\@:
	jr .j3466\@ ; 12t, 2 bytes
.j3466\@:
	jr .j3467\@ ; 12t, 2 bytes
.j3467\@:
	jr .j3468\@ ; 12t, 2 bytes
.j3468\@:
	jr .j3469\@ ; 12t, 2 bytes
.j3469\@:
	jr .j3470\@ ; 12t, 2 bytes
.j3470\@:
	jr .j3471\@ ; 12t, 2 bytes
.j3471\@:
	jr .j3472\@ ; 12t, 2 bytes
.j3472\@:
	jr .j3473\@ ; 12t, 2 bytes
.j3473\@:
	jr .j3474\@ ; 12t, 2 bytes
.j3474\@:
	jr .j3475\@ ; 12t, 2 bytes
.j3475\@:
	jr .j3476\@ ; 12t, 2 bytes
.j3476\@:
	jr .j3477\@ ; 12t, 2 bytes
.j3477\@:
	jr .j3478\@ ; 12t, 2 bytes
.j3478\@:
	jr .j3479\@ ; 12t, 2 bytes
.j3479\@:
	jr .j3480\@ ; 12t, 2 bytes
.j3480\@:
	jr .j3481\@ ; 12t, 2 bytes
.j3481\@:
	ENDM

sleep_300 MACRO
	jr .j3482\@ ; 12t, 2 bytes
.j3482\@:
	jr .j3483\@ ; 12t, 2 bytes
.j3483\@:
	jr .j3484\@ ; 12t, 2 bytes
.j3484\@:
	jr .j3485\@ ; 12t, 2 bytes
.j3485\@:
	jr .j3486\@ ; 12t, 2 bytes
.j3486\@:
	jr .j3487\@ ; 12t, 2 bytes
.j3487\@:
	jr .j3488\@ ; 12t, 2 bytes
.j3488\@:
	jr .j3489\@ ; 12t, 2 bytes
.j3489\@:
	jr .j3490\@ ; 12t, 2 bytes
.j3490\@:
	jr .j3491\@ ; 12t, 2 bytes
.j3491\@:
	jr .j3492\@ ; 12t, 2 bytes
.j3492\@:
	jr .j3493\@ ; 12t, 2 bytes
.j3493\@:
	jr .j3494\@ ; 12t, 2 bytes
.j3494\@:
	jr .j3495\@ ; 12t, 2 bytes
.j3495\@:
	jr .j3496\@ ; 12t, 2 bytes
.j3496\@:
	jr .j3497\@ ; 12t, 2 bytes
.j3497\@:
	jr .j3498\@ ; 12t, 2 bytes
.j3498\@:
	jr .j3499\@ ; 12t, 2 bytes
.j3499\@:
	jr .j3500\@ ; 12t, 2 bytes
.j3500\@:
	jr .j3501\@ ; 12t, 2 bytes
.j3501\@:
	jr .j3502\@ ; 12t, 2 bytes
.j3502\@:
	jr .j3503\@ ; 12t, 2 bytes
.j3503\@:
	jr .j3504\@ ; 12t, 2 bytes
.j3504\@:
	jr .j3505\@ ; 12t, 2 bytes
.j3505\@:
	jr .j3506\@ ; 12t, 2 bytes
.j3506\@:
	ENDM

