for f in Test\ Files/*.p 
do
  echo "Running file $f"
  ./a.out < "$f" > /dev/null
done
