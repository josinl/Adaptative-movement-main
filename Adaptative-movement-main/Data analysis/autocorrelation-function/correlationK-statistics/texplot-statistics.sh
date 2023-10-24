#!/bin/bash

echo -e "What is the file's name ?"

read filename

if [ -e $filename.tex  ]; then
	echo -e "\n"
else
	echo -e "\nThere isn't this file ! \n"
	exit
fi

sed -i '1s/^/\\documentclass[a4paper, 11pt]{article}\n\\usepackage[T1]{fontenc}\n\\usepackage{amsmath,amssymb}\n\\usepackage{textcomp}\n\\usepackage[utf8]{inputenc}\n\\usepackage[portuguese]{babel}\n\\usepackage{gnuplot-lua-tikz}\n\\pagestyle{empty}\n\\usepackage[active,tightpage]{preview}\n\\PreviewEnvironment{tikzpicture}\n\\setlength\\PreviewBorder{2mm}\n\\begin{document}\n/' $filename.tex

echo "\end{document}" >> $filename.tex

pdflatex $filename.tex

rm -f $filename.log
rm -f $filename.aux
rm -f $filename.tex

echo -e "\nOk!\n"


