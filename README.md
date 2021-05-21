# 华科编译原理实验2021

#### 介绍
华中科技大学编译原理实验，设计一个自定义的语言，并进行对于此语言的编译器构建

#### 需要使用的工具
1.  Flex & Bison<br>
    [Flex & Bison下载链接](http://gnuwin32.sourceforge.net/packages/flex.htm)，安装完成后需要配置环境变量。在 **此电脑** -> **属性** -> **高级系统设置** -> **环境变量**中，找到 **Path** 点击 **编辑** 然后 **新建** 一个路径，将Flex&Bison的安装目录的 **Bin** 目录路径添加到其中。
2.  gcc或者g++
    安装完成后同样需要配置环境变量，参考1.中的步骤，将gcc的bin目录路径添加到Path中。

#### 实验二使用说明

1.  在实验二对应目录下打开cmd命令行（即在文件路径中输入cmd回车即可），如图<br>![打开cmd命令行](https://images.gitee.com/uploads/images/2021/0521/143610_3cc74f45_8206880.png "屏幕截图.png")
2.  依次输入如下指令：
```
>flex test.lex
>bison -d parser.y
>gcc -o parser.exe lex.yy.c parser.tab.c ast.c middle.c
```
然后得到parser.exe后，即可进行词法分析的测试
3.  自行写好测试文件`simple.c`然后输入如下指令进行测试：
```
>parser.exe simple.c
```
第一部分输出是词法分析，如果有语法错误，也会进行相应输出；<br>
第二部分输出是抽象语法树，如果前一部分输出语法错误，则这部分不会进行输出；<br>
第三部分第四部分暂时不用管。
4.  如果想要添加或自定义自己的语法，则需要修改的部分只有两个文件，`test.lex`和`parser.y`。<br>
    `test.lex`是词法分析部分，.lex文件的语法不在这里赘述，请自行学习！！！<br>
    `parser.y`是语法分析部分，.y文件的语法不在这里赘述，请自行学习！！！<br>
    `lex.yy.c`是执行 **flex** 指令后得到的生成文件；<br>
    `parser.tab.c`和`parser.tab.h`是执行 **bison** 指令后得到的生成文件；
5.  如果以上指令均运行成功，则输出如下：<br>![词法&语法分析输出样例](https://images.gitee.com/uploads/images/2021/0521/144600_44eff09b_8206880.png "屏幕截图.png")

#### 参与贡献

1.  Fork 本仓库
2.  新建 Feat_xxx 分支
3.  提交代码
4.  新建 Pull Request


#### 特技

1.  使用 Readme\_XXX.md 来支持不同的语言，例如 Readme\_en.md, Readme\_zh.md
2.  Gitee 官方博客 [blog.gitee.com](https://blog.gitee.com)
3.  你可以 [https://gitee.com/explore](https://gitee.com/explore) 这个地址来了解 Gitee 上的优秀开源项目
4.  [GVP](https://gitee.com/gvp) 全称是 Gitee 最有价值开源项目，是综合评定出的优秀开源项目
5.  Gitee 官方提供的使用手册 [https://gitee.com/help](https://gitee.com/help)
6.  Gitee 封面人物是一档用来展示 Gitee 会员风采的栏目 [https://gitee.com/gitee-stars/](https://gitee.com/gitee-stars/)