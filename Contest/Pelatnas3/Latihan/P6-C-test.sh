set -e
g++ P6-C.cpp -o code
g++ P6-C-gen.cpp -o gen
g++ P6-C-brute.cpp -o brute
for((i = 1; ; ++i)); do
    ./gen $i > input_file.txt
    ./code < input_file.txt > myAnswer.txt
    ./brute < input_file.txt > correctAnswer.txt
    diff -Z myAnswer.txt correctAnswer.txt > /dev/null || break
    echo "Passed test: "  $i
done
echo "WA on the following test:"
cat input_file.txt
echo "Your answer is:"
cat myAnswer.txt
echo "Correct answer is:"
cat correctAnswer.txt