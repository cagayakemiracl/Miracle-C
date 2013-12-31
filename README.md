**Q. これは何？**  
**A. C言語でオブジェクト指向プログラミングするためのライブラリです**
#使い方
##コンパイル
**Miracle-Cのライブラリを全て読見込むには**  
\#include "miracle.h"  
**リンクするには**    
-lmiracle -L.
##オブジェクトの生成
**例えばInt(整数)クラスのインスタンスを10で初期化する場合は**  
1. Int i = Int_new(); Set(i, 10);    
2. New(Int, i); Set(i, 10);    
3. Int i = Int_init(10);    
4. Init(Int, i, 10);    
この４つは同じです  
**IntクラスのインスタンスをString(文字列)クラスのインスタンスに変換出来ます**  
String s = To_s(i); Dealloc(i);  
**Stringクラスのインスタンスを入力して表示する場合は**  
New(String, s);  
Get(s)->put(s)->dealloc(s);  
**使い終わったインスタンスはDeallocマクロもしくはdeallocインスタンスメソッドで削除してください**  
Dealloc(i);  
i->dealloc(i);
##配列
**配列を作る事もできます**  
ArrayNew(Int, i, 5);  
**多次元配列も作れます**  
ArrayNew(Int, i, 5);  
Aquarion(i, 3);      ;=> i[5][3];  
**簡単なサンプルコードも用意してます**  
sample/sample.c  
makeコマンドでコンパイル出来るはずです  
#動作確認
* Mac OS X 10.9
    - clang (llvm3.3 デフォ)
    - apple-gcc-4.2  
* Ubuntu 13.04 32bit
   - clang (llvm3.3)
   - gcc4.7.3

#注意
gccでコンパイルする場合は object/lib/object.hファイルを以下のように編集してください  
\#define Method * // gcc用  
//#define Method *const // インスタンスメソッドを定義するマクロ clang用
