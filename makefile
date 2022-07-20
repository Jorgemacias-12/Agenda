compileAndRun: compile run

compile:
	@rm -r dist; mkdir dist
	@g++ src/main.cpp src/functions/utils.cpp -o dist/main.exe

run:
	@cd dist
	@dist/main.exe