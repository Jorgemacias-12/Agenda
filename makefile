compile:
	@rm -r dist; mkdir dist
	@g++ src/main.cpp -o dist/main.exe