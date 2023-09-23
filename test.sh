make
echo ===========  TEST START  ===========

./fixed_point 10 42 add
./fixed_point 42.999 9 add
./fixed_point 9 42.195 add
./fixed_point 3.141592 42.424242 add

./fixed_point 10 42 sub
./fixed_point 42.999 9 sub
./fixed_point 9 42.195 sub
./fixed_point 3.141592 42.424242 sub

./fixed_point 10 42 mul
./fixed_point 42.999 9 mul
./fixed_point 9 42.195 mul
./fixed_point 3.141592 42.424242 mul

./fixed_point 10 42 div
./fixed_point 42.999 9 div
./fixed_point 9 42.195 div
./fixed_point 3.141592 42.424242 div

echo ===========  TEST FINISH ===========
make fclean
