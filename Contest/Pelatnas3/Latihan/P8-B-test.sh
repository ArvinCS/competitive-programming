set -e
g++ P8-B.cpp -o code
g++ P8-B-gen.cpp -o gen
g++ P8-B-checker.cpp -o checker
for((i = 1; ; ++i)); do
	./gen $i > input_file.txt
	./code < input_file.txt > myAnswer.txt
	./checker > checker_log.txt
	echo "Passed test " $i
done