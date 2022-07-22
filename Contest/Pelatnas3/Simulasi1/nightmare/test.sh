set -e
g++ sol.cpp -o sol
g++ brute.cpp -o brute
g++ gen.cpp -o gen
for((i=0;;++i)); do
	./gen.exe > input.txt
	./sol.exe < input.txt > ans.txt
	./brute.exe < input.txt > correct.txt
	diff -Z ans.txt correct.txt > /dev/null || break
done