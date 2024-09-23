学习来自 [毛怪][here]
那现在是已经下好各种插件可以直接使用了
右边会有一个查看书页的图标实际上是md的preview
具体实现的时候空格加删看情况，多试试就好
##### 一定要注意所有符号都是半角！！！

# Markdown基本语法

1. **标题**

    #一级标题
    ##二级标题
    最多6级
    (当然也可以用 1. ** tittle ** 来实现)

2.**引用**
> 这里是引用示例
> > 二级引用

语法是 > + 引用内容
但不知道为何 按tab以后就不行了（

3. **列表**
    1. 无序列表
    - 列表1 （- + * 都行）
    + 列表2
    * 列表3
    2. 有序列表 （前边带数字 加空格）
    3. 嵌套 （嵌套就是按tab 直接变罗马数字）
    4. TodoList
        - [x] a
        - [ ] b
        - [ ] c

4. **表格**
    | 左对齐 | 居中对齐 | 右对齐 |
    | :----- | :----: | ----: |
    | a | b | c |

    markdown 文件中显示的第二行是对齐方案， "-" 个数任取
    

5. **段落**
    - 换行？ 两个以上空格
    + 分割线 三个*
        ***
    - 字体
        | 字体 | 代码 |
        | :-: | :-: |
        | *斜体* | * * |
        | ==高亮== | == == |
        | **粗体** | ** ** |
        | ***斜粗体*** | *** *** |
        | ~~删除~~ | ~~ ~~ |
        | <u>下划线</u> | ``` <u> </u>```|
    - 脚注   
    引用文献 [^1]


6. **代码**
```

#include <stdio.h>
#include "max.h"
#include "min.h"

int a,b;

int main()
{
    scanf("%d%d",&a,&b);
    printf("Max: %d\n",max(a,b));
    printf("Min: %d\n",min(a,b));
}

```
` get min & max `

7. **超链接**

    -  [这是一个超链接] : https://github.com/iKalous/github_study-remote
    -  还有一个[click here][repository]


8. **图片**
   - 使用图床保存图片并实现插入
        [路过图床]: https://imgse.com/
    - 使用markdown语法插入
    [![pAMdVeJ.png](https://s21.ax1x.com/2024/09/21/pAMdVeJ.png)](https://imgse.com/i/pAMdVeJ)
    直接把给的markdown代码贴过来即可
    - 使用html语言实现调整图片大小和位置的功能
        <a herf = "https://imgse.com/i/pAMdVeJ"><div align=center><img src = "https://s21.ax1x.com/2024/09/21/pAMdVeJ.png" alt = "pAMdVeJ.png" border = "0" width = 80% height = 80%/></div></a>

9. **插入latex公式**
    - 行内显示公式：
        $f(x) = ax + b$
    - 块内显示数学表达式：
    $$
    \begin{Bmatrix}
        a & b \\
        c & d
    \end{Bmatrix}
    $$


10. **个性化设置**

    - 用html语法来实现，直接看看效果吧
## <center><font face = "仿宋" font color = green size = 5> Firefly </font>


- (目前html的语法我掌握的并不多，所以还得多学习呢)
    - css 语法实现
    - ctrl shift p 搜索 "Markdown Preview Enhanced:Customize CSS"
    - 然后就可以实现标题的自定义
- 再者就是 file preferences settings
  
11. **PDF导出**
    在preview里面用浏览器打开再下载回来




以下为测试语句效果使用
- [^1]: 论文
- [repository]: https://github.com/iKalous/git_study-remote
- [here]: https://www.bilibili.com/video/BV1bK4y1i7BY/?spm_id_from=333.337.search-card.all.click&vd_source=c4a121c9752c0468a419b2f4edda7bbe