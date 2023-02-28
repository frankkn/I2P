gcc E02_04.c -o E02_04
echo "5 6" | ./E02_04 > out
echo "11" > ans
diff ans out
ret=$? # $?: the return code of the previously run command

if [[ $ret -eq 0 ]]; then
    echo "All accepted."
else
    echo "Wrong answer."
fi