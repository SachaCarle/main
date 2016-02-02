./calc
echo

./calc ""
echo

./calc "" ""
echo

./calc "" "" ""
echo

echo "1+1" | ./calc "()+-*/%" "0123456789" "3"
echo

echo "o-o" | ./calc "o" "()+-*/%" "3"
echo

echo "1+1" | ./calc "00123456789" "()+-*/%" "3"
echo

echo "1p1" | ./calc "0123456789" "[]pmfdm" "3"
echo

echo "1P1" | ./calc "0123456789" "()PMFD0" "3"
echo

echo "1+1" | ./calc "0123456789" "[]pmfdo" "3"
echo

echo "6+9" | ./calc "01" "()+-*/%" "3"
echo

echo "1+1" | ./calc "0123456789" "()+-*/%" "3"
echo

echo "1" | ./calc "0123456789" "()+-*/%" "1"
echo

echo "+1" | ./calc "0123456789" "()+-*/%" "2" # ERREUR DE MALLOC
echo

echo "1+" | ./calc "0123456789" "()+-*/%" "2" # \\ same
echo

echo "+" | ./calc "0123456789" "()+-*/%" "1" #segfault
echo

echo "56+67-1+3+67" | ./calc "0123456789" "()+-*/%" "12"
echo

echo "1p1" | ./calc "0123456789" "[]pmfdo" "3"
echo

echo "1+1" | ./calc "0123456789" "[]pmfdo" "3" 
echo

echo "1234567890-12345678901234567890" | ./calc "0123456789" "()+-*/%" "31"
echo

echo "56p67m[1p3]p67" | ./calc "0123456789" "[]pmfdo" "14"
echo

echo "100000*(1234513+61513)/(6715-4)+67132*(6%2)+000000000000000000000000" | ./calc "0123456789" "()+-*/%" "60" #segfault
echo

echo "((((((((((1+1))))))))))" | ./calc "0123456789" "()+-*/%" "23"
echo

echo "()" | ./calc "0123456789" "()+-*/%" "2" #bus error + latence
echo

echo ")" | ./calc "0123456789" "()+-*/%" "1"
echo

echo "(" | ./calc "0123456789" "()+-*/%" "1"
echo

echo "-" | ./calc "0123456789" "()+-*/%" "1"
echo

echo "6-5*(7+6" | ./calc "0123456789" "()+-*/%" "8"
echo

echo "5-8*8)" | ./calc "0123456789" "()+-*/%" "6"
echo

echo "" | ./calc "0123456789" "()+-*/%" "0"
echo

echo ")(" | ./calc "0123456789" "()+-*/%" "2" #segfault
echo

echo "101-100" | ./calc "01" "()+-*/%" "7"
echo

echo "56-78" | ./calc "01" "()+-*/%" "5"
echo

echo "c-b*c" | ./calc "abc" "()+-*/%" "5"
echo

echo "FFFd|EEEm111/" | ./calc "0123456789ABCDEF" "|/pmfdo" "13"
echo

echo "10d0" | ./calc "0123456789ABCDEF" "<>pmfdo" "4"
echo

echo "FOOBAR" | ./calc "RBFO" "()+-*/A" "6"

echo "Test caractère d'échapement" 
echo

echo "3--1" | ./calc "0123456789" "()+-*/%" "4"
echo

echo "5--+-8" | ./calc "0123456789" "()+-*/%" "6"
echo

echo "5*(-6)" | ./calc "0123456789" "()+-*/%" "6"
echo

echo "5*(6)" | ./calc "0123456789" "()+-*/%" "5"
echo

echo "5*-1" | ./calc "0123456789" "()+-*/%" "4"
echo

echo "5-9+7/-8+67*(8+--7)/-2+1" | ./calc "0123456789" "()+-*/%" "24"
echo

echo "5-9+7/-8" | ./calc "013456789" "()+-*/%" "8"
echo

echo "67*(8+--7)/-2+1" | ./calc "0123456789" "()+-*/%" "15"
echo

echo "67*(8+--7)" | ./calc "0123456789" "()+-*/%" "10"
echo

echo "1005/-2+1" | ./calc "0123456789" "()+-*/%" "9"
echo

echo "675645*0" | ./calc "0123456789" "()+-*/%" "8"
echo

