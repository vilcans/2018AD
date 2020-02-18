

imodium-comp.png: imodium.jpg
	python derezz.py --left=1000 --top=754 --height=580 \
		--thresholds=130,190 \
		--blurs=25,20 \
		--composite=$@ $<

morbid-comp.png: morbid.jpg
	python derezz.py --left=819 --top=543 --height=600 \
		--thresholds=40,80 \
		--blurs=5,15 \
		--composite=$@ $<

vilcans-comp.png: vilcans.jpg
	python derezz.py --left=633 --top=710 --height=781 \
		--thresholds=130,145 \
		--blurs=5,5 \
		--composite=$@ $<

corel-comp.png: corel.png
	python derezz.py --left=8 --top=116 --height=293 \
		--thresholds=130,190 \
		--blurs=5,5 \
		--composite=$@ $<
