# replaces tabs with 4 spaces and generates an txt file for submission
sed 's/\t/    /g' main.cpp > output.txt
echo "\n----------RUN----------\n" >> output.txt
g++ main.cpp -std=c++11
./a.out >> output.txt
echo "\n-----------------------\n" >> output.txt
cat output.txt