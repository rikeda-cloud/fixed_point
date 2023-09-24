# fixed_point

## test.shの使い方
* 固定小数点(int)       -> \./test.sh
* 固定小数点(long)      -> \./test.sh long
* 固定小数点(long long) -> \./test.sh llong
* 浮動小数点(double)    -> \./test.sh double
* 浮動小数点(float)     -> \./test.sh float

## 独自のテストの実行
* test.sh内に、./fixed_point [ <font color="#000000">***value1***</font> ] [ <font color="#000000">***value2***</font> ] [ <font color="#FF0000">***add***</font> | <font color="#00FF00">***sub***</font> | <font color="#0000FF">***mul***</font> | <font color="#FF00FF">***div***</font> ]の形式で書く
    * <font color="#FF0000">***add***</font> -> <font color="#FF0000">***足し算***</font>
    * <font color="#00FF00">***sub***</font> -> <font color="#00FF00">***引き算***</font>
    * <font color="#0000FF">***mul***</font> -> <font color="#0000FF">***掛け算***</font>
    * <font color="#FF00FF">***div***</font> -> <font color="#FF00FF">***割り算***</font>

## ベンチマークテストの実行
* Makefile内のSRCS += $(SRCS_DIR)main.cをコメントアウト
* Makefile内のSRCS += $(SRCS_DIR)benchmark.cのコメントアウトを解除
    * 直接コンパイルで実行
        * make でt_fixed型の型をint型でコンパイル
        * make [ double | float | long | llong ] でt_fixed型の型を指定してコンパイル
        * ./fixed_point で実行
    * test.shを使用して実行
        * \./test.sh でt_fixed型の型をint型で実行
        * \./test.sh [ long | llong | double | float ] でt_fixed型の型を指定して実行
