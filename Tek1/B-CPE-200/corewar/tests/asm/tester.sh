#!/bin/bash

OK=0
KO=0

if [ ! -f ../../asm/asm ]
then
    echo -e "\e[31mError: asm not found, please compile it first\e[0m"
    exit 1
else
    cp ../../asm/asm .
fi

for file in valid_champions/*.s
do
    ./asm $file
    if [ $? -eq 0 ]
    then
        mv ${file%.*}.cor $(echo "$file" | cut -d '/' -f 2 | cut -d '.' -f 1)-my.cor
    else
        KO=$((KO+1))
    fi
done

for file in valid_champions/*.s
do
    FILE_CUT=$(echo "$file" | cut -d '/' -f 2 | cut -d '.' -f 1)
    ./ref $file
    mv $FILE_CUT.cor $FILE_CUT-ref.cor
done

for file in ./*-my.cor
do
    FILE_A=$(echo "$file" | cut -d '/' -f 2 | cut -d '.' -f 1 | cut -d '-' -f 1)
    hexdump -C $file > $FILE_A-my.hex
    hexdump -C $FILE_A-ref.cor > $FILE_A-ref.hex
    diff $FILE_A-my.hex $FILE_A-ref.hex
    if [ $? -eq 0 ]
    then
        echo -e "$FILE_A.s: \e[32mOK\e[0m"
        OK=$((OK+1))
    else
        echo -e "$FILE_A.s: \e[31mKO\e[0m"
        KO=$((KO+1))
    fi
done

rm -f ./*.hex
rm -f ./*.cor

echo -e "\n\e[34mRESUME\e[0m"
echo -e "\e[32mOK: $OK\e[0m"
echo -e "\e[31mKO: $KO\e[0m"

if [ $KO -eq 0 ]
then
    exit 0
else
    exit 1
fi
