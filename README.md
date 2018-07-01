# MultiCoreLab

Lab for Multi-core Based Parallel Programming.

# Assignment 1
    
要求：尽量用自己的话；在每道题后给出主要参考文献。

## 1. 简述下列 5 种并行计算机系统结构，并为每种指出 2 个独特特性（独特特性是指在任何其他系统结构中没有的）

1. PVP
2. SMP
3. MPP 
4. COW 
5. DSM
    
## 2. 名词解释（与存储器访问相关的术语）

1. UMA
2. NUMA
3. COMA
4. DSM
5. NORMA

# Assignment 2

## 1. 复习，论述以下问题

1. 何谓 cache？何谓 buffer？各自的目的为何？
2. 何谓并发（concurrent）？何谓并行（parallel）？两者有何联系与区别？
3. 何谓线程（thread）？何谓进程（process）？线程有哪些支持/实现方法？
4. 何谓指令流水线（Instruction pipeline）？

## 2. 编程

查找 1 ~ N 之间的所有素数（N 可以为十万、一百万或一千万等）。先用串行程序，再分别将 其并行化（多线程程序，同时提供 `Windows API` 和 `POSIX Thread` 版），并在各自平台上对性能进行分析。

要求：给出源代码及性能分析的文档。（文档中需要给出程序运行的串行时间，并行时间，加速比，并对当前性能好坏的原因做一定的分析）

# Assignment 3

## 编程

查找 1 ~ N 之间的所有素数（N 可以为十万、一百万或一千万等），用 `OpenMP` 将其并行化，对性能进行分析。

要求：给出源代码及性能分析的文档。（文档中需要给出程序运行的串行时间，并行时间，加速比，并对当前性能好坏的原因做一定的分析）

**注意事项**

* Visual Studio 2017 中，要把`项目属性 -> 配置属性 -> C/C++ -> 语言 -> OpenMP 支持`设为`是`。