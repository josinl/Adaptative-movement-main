!/bin/bash
clear

echo -e "\n Compiling - Running "

rm -f prey_nutrition.dat

make

./executable

gnuplot plots.gnu


rm -r executable

echo -e "\nOk !\n"
