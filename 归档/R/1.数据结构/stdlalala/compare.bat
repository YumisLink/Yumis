@echo off
set t=1000
for /l %%i in (1,1,%t%) do (
	gen.exe
	editor.exe
	editorforce.exe
	fc editor.out editor.ans >> report.log
)
pause