# C语言笔记
本笔记主要参考：


- [C语言笔记](#c语言笔记)
  - [第8章 指针](#第8章-指针)
    - [第一部分](#第一部分)
      - [7.1 什么是指针](#71-什么是指针)
      - [7.2 变量值指针和指向变量的指针变量](#72-变量值指针和指向变量的指针变量)

## 第8章 指针
由于客观条件限制（忘带书了），本笔记第一部分先根据《C程序设计教程（第三版）》记录，第二部分再使用《C程序设计（第五版）》记录。
<br/><br/>

### 第一部分
#### 7.1 什么是指针
1. 内存的地址、内存的内容  
    - 内存的地址：被占用内存的空间编号  
    - 内存的内容：存在某部分内存中的内容，如变量等
2. 直接访问、间接访问  
    - 直接访问：按变量地址存取变量值的方式  
    - 间接访问：
3. 指向：地址指向变量
4. 指针、指针变量
    - 指针：地址的值，可以是指针变量代表的值
    - 指针变量：变量，代表某一指针的变量

#### 7.2 变量值指针和指向变量的指针变量  
1. **指针运算符**、**取地址运算符** 
    ```C
    float a;                //定义a, float型
    int * pointer_1;        //定义pionter_1, int*型
    pointer_1=&a;           //把a的地址赋给pointer_1
    ``` 
    - 指针运算符（*）：`&a`是`float`变量`a`的地址
    - 取地址运算符（&）：`*p`是指针变量`p`指向的变量的值  
    > **注意：** <code class="language-C">\*pointer</code>有两层含义——  
    >   1. 声明变量：<code class="language-C">int *pointer;</code>
    >   2. 指针运算符：<code class="language-C">\*pointer=a;</code>
2. **基类型**：指针变量指向的变量的类型
3. 指针变量的定义：  
    <kbd>基类型</kbd>+<kbd>space</kbd>+<kbd>\*</kbd>+<kbd>指针变量名</kbd>  
    > **注意：** 
    > 1. 变量是<kbd>指针变量名</kbd>，而非"<kbd>\*指针变量名</kbd>"  
    > 2. 定义指针变量时**必须指定基类型**。（原因？变量类型不同，占的内存大小不同）
4. 指针变量的赋值    
     ```c
    float a;
    float *pinter_a;
    pointer_a=&a;         //赋值语句
    ```
    > **注意：**  
    > 1. **赋值给地址时**，只能令 `左地址变量=&变量` ；若 `*左地址变量=值` ，则赋值给了**指针指向的变量**。 e.g.  
    >       ```c
    >       pointer_a = &a;    //“左地址变量=&变量”，含义为把a的地址赋给pointer_a
    >       *pointer_a = 1.0； //“左地址变量=值”，含义为a=1.0
    >       *pointer_a = a;    //含义同*pointer_a = 1.0
    > 
    >       **pointer_a = a;   //二级指针，即“变量pointer_a” 指向了另一个指针变量，且后者指向 “变量a”
    >       *pointer_a = &a;   //二级指针，等同于 **pointer_a = a
    >     ```
    > 1. 指针的基类型和指针指向的变量类型必须相同。 
    > 1. **赋值给指针指向的变量**
    >       ```c
    >       //变量声明
    >       int a, *pointer_a, b, *pointer_b, *pointer_temp;
    >       pointer_a=&a;
    >       pointer_b=&b;
    > 
    >       //赋值
    >       a = *pointer_b;               //把b的值赋给a
    >       *pointer_a = b;               //把a的值赋给b
    >       *pointer_temp = *pointer_b    //错误！！！因为 变量pointer_temp 没有赋值，可以指向任意地址，赋值给位置地址变量后，程序很可能就崩溃了
    >       ```
    >   > 注意：
    >   > 1. <code class="language-C">\*p1=\*p2</code> 不是一定不能用，但一定要注意 <code class="language-C">\*p1</code> 必须有过*指针变量值的初始化*。
    >   > 2. <code class="language-C">p1=p2</code> 不受影响，因为这里只改变了p1的指向，没有改变具体的（非指针变量的）值
5.  - [ ] 指针变量的作用：（例7.2,例7.2\_Wrong,例7.3）形参不能传递值给实参，但借助指针变量实现功能。指针变量可以起到以下两个目的：   
        1. 改变实参；
        1. 功能函数返回一个以上的返回值；
    > 修改数据的4种有效办法和2种错误办法：
    >   - 正确办法
    >       1. 在 <code class="language-C">main</code> 中直接赋值；
    >       1. 在 <code class="language-C">main</code> 中调换指针(e.g.例7.2)；
    >       1. 定义 <code class="language-C">function(int \*p)</code> ，修改 <code class="language-C">\*p</code> 的值；  
    >            &emsp; \<\!\-\-**最推荐！符合程序化设计需要**\-\-\>
    >       1. 用 <code class="language-C">statics</code> 变量  
    >            &emsp; \<\!\-\-有特殊需要才用\-\-\>
    >   - 错误办法
    >       1. 定义 <code class="language-C">function(int a)</code> ，修改 <code class="language-C">a</code> 的值； 
    >           > 错误原因：形参不能传递值回实参；
    >       1. 定义 <code class="language-C">function(int \*p)</code> ，修改 <code class="language-C">p</code> 的值； 
    >           > 错误原因：形参不能传递值回实参，**即使是指针变量也不行！！！**
6. 