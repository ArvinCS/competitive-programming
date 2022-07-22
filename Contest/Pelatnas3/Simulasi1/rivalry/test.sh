set -e

for((i=0;;++i)); do
	./rivalry.exe << sample_1.in >> output.txt
done