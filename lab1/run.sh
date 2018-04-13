# replaces tabs with 4 spaces and generates an txt file for submission
sed -i 's/\t/    /g' main.cpp && cat main.cpp > output.txt && echo "\n-----------RUN-----------\n" >> output.txt && g++ main.cpp && ./a.out >> output.txt && echo "\n----------------------\n" >> output.txt && cat output.txt
