# Comment

test.html : head.txt body.txt foot.txt
	@echo Creating HTML ...
	@type head.txt body.txt foot.txt > test.html

body.txt : body1.txt body2.txt
	@echo Creating TXT ...
	@type body1.txt body2.txt > body.txt

show:
	cls
	type .\test.html

run:
	"C:\Program Files\Firefox\firefox.exe" "file://K:\Source\C\make4html\test.html"
	
clean:
	@echo Deleting HTML ...
	del test.html

#  =============  EOF  =============
