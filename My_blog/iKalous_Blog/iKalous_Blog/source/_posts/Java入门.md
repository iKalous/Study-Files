<head>
    <style>
        #center { 
            text-align : center;
        }
        p {
            line-height : 30px;
            text-indent : 2em;
            /* text-size : 10px; */
            /* 设置字体大小 */
        }
        #small {
            font-size : 13px;
        }
        #big {
            font-size : 20px;
        }
    </style>
</head>


<h1 id="center"> Java入门总结 </h1>

<h4> 前言</h4>

<p id = "small">
大概是花了一周左右的时间速通了黑马的入门课，准备继续web开发那一块，但是在做作业的过程中还是发现有很多东西掌握的不是很好，所以还是花点时间过一下加深一下印象。
</p>


<p id="small">
目前而言是从语法的角度来写，所以很多业内常用的东西不会涉及，但可能会提到
</p>

 虽然软工一课程设置相较于CPL ~~比较逆天~~ ，但其实这才是真正能学到本领的教学方式


<h2 id="center">
Part1: 基础语法
</h2>

<p id="small">
评价是够用就行
</p>

实际上Java大部分的基础语法和C/C++是一样的，所以这里只是会简单列举一下常用的一些函数。

```
//输入
Scanner scanner = new Scanner(System.in);

string str = scanner.nextLine();
int num = scanner.nextInt();
double num = scanner.nextDouble();

scanner.close(); // 最后记得关闭scanner

//输出
System.out.println("Hello World");

//数组
int[] arr = new int[10];

//ArrayList
ArrayList<Integer> list = new ArrayList<>();
list.add(1);

//ArrayList 和 List 的区别
ArrayList<Integer> list = new ArrayList<>();
List lst = list; // 这里是向上转型

//List的构造器使用依赖于ArrayList
```

Java中提供了许多方便的方法和类，比较常用的是toString，equals。值得注意的是这里的String类本质上是一个对象，封装了一个final修饰的数组，因此不能直接修改其中的元素。


<h2 id="center">
Part2: 面向对象
</h2>


<p id="small">
这算是java的思想核心了，和C的面向过程还是有很大的不同。
</p>

<h3>
操作指南省流：合理暴露，合理隐藏
</h3>

<h3>
内存分配
</h3>

<p>
根据我的浅薄理解，java的内存区分为堆内存区、栈内存区和方法区。栈内存区和C是一样的，简单而言就是变量数值的存储。方法区简单理解成运行内存（不知道对不对233）。比较特殊的是堆内存区，这里存储的是创建的实例对象。
</p>
<p>
java中没有指针，这看似使得访问内存变得不方便了，但实际上你在创建一个实例的时候，比如
</p>

```
A a = new A();
```
<p>
此时a这个东西拿到的是创建的实例的堆内存地址。如果把a作为参数传入函数，此时相当于将该实例的地址传入，达到了指针的效果。
</p>


<h3>
对象内的基本组成部分
</h3>

<h4>
1. Constructor, setter&getter
</h4>

<p>
构造器可选有参和无参，默认自带无参构造器，在自定义了有参构造器以后，无参构造器默认会失效，此时再想调用无参构造器需要手动设置。
</p>
<p>
getter & setter 这两个算是合理暴露，合理隐藏的核心了。对于Javabean（实体类），成员变量私有的情况就需要这样公开的方法去访问这些数据。这样更安全。
</p>

<h4>
2. 基础修饰字
</h4>

 - public： 公开，可以访问
 - private： 私有，外部不能访问
 - protected： 保护，同包内可以访问，不同包内不能访问，但是不同包内子类可以访问

 - final：  最终，不能被继承，外部也无法直接修改
 - static：  静态，属于类，而不是实例，在该类第一次创建对象的时候被加载，所有该类的成员共享一份
 - static final：  常量，不能被修改，且必须初始化（类似于const）
 - staitc修饰方法的时候， 该方法能访问类的静态成员，不能访问实例成员。如需访问实例成员，需要创建该类的实例间接访问。
 - this&super:  this代表当前实例，super代表当前类的父类实例。一般使用在构造器中防止变量名冲突。

 <h3>
 继承和多态
 </h3>

 <p>
 同样是很重要的部分，增强代码的可维护性和解耦合性。人话：拼好码
 </p>

 <h4>
 继承
 </h4>

<p>
只能继承一个父类。想要继承多个父类的话那是接口的事。
</p>
<p>
上面的关键字可以实现继承中控制地继承需要的东西和隐藏需要保密的东西。而对于继承一个父类的子类其中很重要的一点是子类可以重写父类的方法，提示词是@Override。
</p>


