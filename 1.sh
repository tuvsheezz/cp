a=0
while [ "$a" -lt 5 ]
do
    echo "Hi" >> aaa.tx
    git add .
    git commit -m $a
    git push origin main
    echo $a
done