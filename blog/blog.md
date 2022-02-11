## 第一阶段博客：

主要以小组会议的形式讨论了编码设计规范，进行了数据初步整理归纳，MVC架构设计，并创立和完成了数据设计文档，静态模型、动态模型、功能模型说明文档，因为框架暂时较为简单，考虑到后续可能会有的需求变更，并未进行具体编码的工作。

**Task0:填写PSP表格的估计部分**

## PSP表格

| PSP2.1                                  | Personal Software Process Stages        | 预估耗时（分钟） | 实际耗时（分钟） |
| :-------------------------------------- | :-------------------------------------- | :--------------: | :--------------: |
| Planning                                | 计划                                    |        10        |                  |
| · Estimate                              | · 估计这个任务需要多少时间              |        10        |                  |
| Development                             | 开发                                    |       500        |                  |
| · Analysis                              | · 需求分析 (包括学习新技术)             |        30        |                  |
| · Design Spec                           | · 生成设计文档                          |        80        |                  |
| · Design Review                         | · 设计复审 (和同事审核设计文档)         |        10        |                  |
| · Coding Standard                       | · 代码规范 (为目前的开发制定合适的规范) |        30        |                  |
| · Design                                | · 具体设计                              |        60        |                  |
| · Coding                                | · 具体编码                              |       170        |                  |
| · Code Review                           | · 代码复审                              |        30        |                  |
| · Test                                  | · 测试（自我测试，修改代码，提交修改）  |        90        |                  |
| Reporting                               | 报告                                    |       120        |                  |
| · Test Report                           | · 测试报告                              |        60        |                  |
| · Size Measurement                      | · 计算工作量                            |        40        |                  |
| · Postmortem & Process Improvement Plan | · 事后总结, 并提出过程改进计划          |        20        |                  |
|                                         | 合计                                    |       630        |                  |

##### **Task1:对需求进行分析整理数据，采用人工整理的方式**

- **beijing-subway.txt**:储存每条线路的站点，和对应的换乘线路，格式如下：

  **线路名称**：1号线

  **线路编号**：1

  **站点数量**：23

  **站点名字 换乘数量 换乘线路**：

  苹果园 0
  古城 0
  八角游乐园 0
  八宝山 0
  玉泉路 0
  五棵松 0
  万寿路 0
  公主坟 1 10
  军事博物馆 1 9

- **line.txt**：存储线路编号，格式如下：

  **线路编号 线路名称：**

  1 1号线
  2 2号线
  3 八通线

- **station.txt**:存储站点编号、名称、所在线路，格式如下：

  **编号，站点名称，所在线路数量，线路编号：**

  1 苹果园 0
  2 古城 0
  3 八角游乐园 0
  4 八宝山 0
  5 玉泉路 0
  6 五棵松 0
  7 万寿路 0
  8 公主坟 2 1 10
  9 军事博物馆 2 1 9

**Task2:初步确定MVC架构**

​       设计编写"data model", "command controller", "display subway line"三个模块来实现此任务。这里是程序第一次详细设计，我们采用MVC设计模式。其中"data model"和"display subway line"属于**Model**，"command controller"属于**Controller**，由于是命令行程序，考虑到后续可能的界面设计，并未详细设计属于**View**的User，但为其保留了设计空间。

**Task3:确定编码设计规范和数据设计文档**

- 编码设计规范：主要包括变量、常数的命名规范；文件表头、函数说明、注释的布局规范；以及确定良好的代码风格。

- 数据描述

  | 数据名称              | 数据类型 | 描述                                |
  | --------------------- | -------- | ----------------------------------- |
  | lineID                | int      | 地铁线路编号                        |
  | lineName              | string   | 地铁线路名称                        |
  | stationID             | int      | 地铁站点编号                        |
  | stationBelongToLineID | int      | 站点属于线路的编号                  |
  | stationsOnLineID      | int      | 属于当前线路的站点的编号            |
  | stationName           | string   | 地铁站点名称                        |
  | transferNumber        | int      | 站点可换乘线路的数量，0表示不可换乘 |
  | transferLineID        | int      | 站点可以换乘的线路编号              |
  | inputStartStationName | string   | 用户输入起始站点名称                |
  | inputEndStationName   | string   | 用户输入终止站点名称                |
  | inputStartStationID   | int      | 用户输入起始站点编号                |
  | inputEndStationID     | int      | 用户输入终止站点编号                |
  | inputLineName         | string   | 用户输入线路名称                    |
  | inputLineID           | int      | 用户输入线路编号                    |
  | commandOption         | string   | 用户输入的指令类型                  |
  | errorFlag             | bool     | 用于指示程序中已出现错误            |

**Task4**:**构建第一阶段的静态模型、动态模型、功能模型说明文档**

我们采用小组会议的形式，针对第一阶段的需求进行了共同讨论和面向对象的分析与设计。通过对静态模型、动态模型和功能模型的构建分析出程序的框架，并在会议期间利用iPad协作画图得出UML草图，随后结束会议，再各自利用电脑画出更为正式的UML图。

+ 草图

![顺序图-查询路径草图](C:/Users/halfrot/Documents/GitHub/Software-Engineering-Project/blog/assets/顺序图-查询路径草图.jpg)

![顺序图-查询线路草图 ](C:/Users/halfrot/Documents/GitHub/Software-Engineering-Project/blog/assets/顺序图-查询线路草图 .jpg)

![用例图草图](C:/Users/halfrot/Documents/GitHub/Software-Engineering-Project/blog/assets/用例图草图.jpg)

![状态图草图](C:/Users/halfrot/Documents/GitHub/Software-Engineering-Project/blog/assets/状态图草图.jpg)

+ 工具绘图

![包图](C:/Users/halfrot/Documents/GitHub/Software-Engineering-Project/blog/assets/包图.svg)

![类图](C:/Users/halfrot/Documents/GitHub/Software-Engineering-Project/blog/assets/类图.svg)

![顺序图——遍历站点](C:/Users/halfrot/Documents/GitHub/Software-Engineering-Project/blog/assets/顺序图——遍历站点.svg)

![顺序图——查询线路](C:/Users/halfrot/Documents/GitHub/Software-Engineering-Project/blog/assets/顺序图——查询线路.svg)

![顺序图——查询有效路径](C:/Users/halfrot/Documents/GitHub/Software-Engineering-Project/blog/assets/顺序图——查询有效路径.svg)

![状态图——遍历站点](C:/Users/halfrot/Documents/GitHub/Software-Engineering-Project/blog/assets/状态图——遍历站点.svg)

![状态图——查询线路](C:/Users/halfrot/Documents/GitHub/Software-Engineering-Project/blog/assets/状态图——查询线路.svg)

![状态图——查询最有效路径](C:/Users/halfrot/Documents/GitHub/Software-Engineering-Project/blog/assets/状态图——查询最有效路径.svg)

**Task5:寻找资料并进行学习**

小组在网上寻找了资料，并在会议期间对博客要求学习的内容进行了交流。

## 第二阶段博客

第二阶段我们继续在第一阶段的基础上完善了面向对象的设计工作，并根据第二阶段的需求补充了文档内容。然后，在进入具体编码之前，我们对之前的文档进行了精化设计，得出了更加具体和详细的UML图，方便后续的实现工作。

**Task1:精化类图，完善MVC架构，更新面向对象设计文档**

### MVC结构:

 **View**

+ User

**Controller**

+ Controller
+ CommandController
+ ResultController
+ RequestFileController
+ SendFileController

**Model**

+ Subway
+ Line
+ Station
+ File

具体关系为，View和Model之间通过Controller进行间接联系，Model和Model之间同样通过Controller进行间接联系。Controller应该具有直接通信View和Model的权力。

**优点**：这样设计虽然会增加代码量，更加繁琐，但是模块之间逻辑清晰，调整接口容易，实现高内聚，低耦合，有利于应对需求变更和软件长期维护的挑战。

### 单例设计：

其中为单例设计模式的为：

User, Subway, File

### 抽象工厂：

为抽象工厂设计模式的为：

Controller

### 类间关系：

**User: **CommandController, ResultController

**CommandController:** User, Subway

**ResultController:** User, Subway

**LineFileController:** Line, File

**FileLineController:** Line, File

**Line:** LineFileController, FileLineController, Subway

**Subway:** Line, CommandController, ResultController

**Station:** Line

**File:** LineFileController, FileLineController

**Controller:** CommandController, ResultController, LineFileController, FileLineController

### 接口设计

User

留有以下三个接口用于从ResultController接收结果

```
	void PrintLine(Line line);
	void PrintPath(std::vector<std::string> vec, bool plusFlag = false);
	void PrintResult(std::string testResult);
```

使用以下接口向CommandController传输指令

```
	void CommandLine(int argc, char* argv[]);
	void ReadRawCommand();
```

Controller

所有的Controller的派生类均只有以下接口进行消息的解析，但不同的Controller作用不同，实现不同，使用了多态机制进行实现

```
	Parse()
```

File

用于和Station进行通信，传递每条线的信息，还有存有站点信息的map

```
	Line ReadLine(int lineNumber);
	void SendMap();
```

Station

前三个接口用于和File类进行信息的沟通，后三个接口实现了功能函数

```
	void SaveLine(Line line);
	Line LineQuery(int lineNumber, bool saveFlag = false);
	void SaveStationNameMap(const std::map<std::string, int>& map);
	
	std::vector<std::string> CalPath(std::string start, std::string end, bool saveFlag = false);
	std::vector<Station> TravelAllPath(std::string start, bool plusFlag = false);
	std::string FileTest(std::string fileName);
```

**Task2 对第一阶段模型（UML）进行修改：**

- 对功能模型添加用例与用例描述
- 对静态模型添加线路类方法，类描述等
- 对顺序图和活动图添加功能等

![面向对象设计-包图](C:/Users/halfrot/Documents/GitHub/Software-Engineering-Project/blog/assets/面向对象设计-包图.svg)

![面向对象设计-精化类图](C:/Users/halfrot/Documents/GitHub/Software-Engineering-Project/blog/assets/面向对象设计-精化类图.svg)

**Task3 实现与优化**

+ 实现遍历

使用了简单的建图BFS算法，可以实现精确求解。

+ 换乘优化+3

由于此问题为NP-Hard问题，无法在短时间精确求解，于是采用了模拟退火算法。

通过构造站点的访问顺序序列，并且每次随机交换两个站点，由此逐步逼近最优解。

为了缓解速度上的不足，还采用了弗洛伊德算法进行预处理，并将较好的序列作为超参数保存在文件good_arg.txt中。

对于换乘问题，我们直接对弗洛伊德算法进行改进，修改两点间的路径代价即可实现。

## 第三阶段博客

主要完成了界面设计、前后端整合、代码优化和总结的工作

开会截图：![20220211](C:\Users\halfrot\Documents\GitHub\Software-Engineering-Project\blog\assets\20220211.png)

**Task1:界面设计**：VS2019,C#

- ![界面](C:\Users\halfrot\Documents\GitHub\Software-Engineering-Project\blog\assets\界面.png)

- 过程介绍：

  - 界面三个确认按钮对应三种功能：线路查询、最短路查询、遍历查询。点击确认之后即开始画路线，其中蓝色方块代表当前点，红色方块代表走过的点，相邻两点之间用黑色箭头连接从而形成路线。最后在界面右下角显示本次出行经过的站点数。

- **具体实现**：

  ***数据整理**：确定界面设计之后，为了实现点对点的画图，首先需要整理出地图坐标数据需要人工测量界面上每个站点的坐标，最后整合出Map.txt，包含每一个站点和对应的坐标x,y值。

  ***重点代码实现：**

  - **定义工具类DrawTools**：包含Drawline（画线）,DrawBlue（当前站点蓝色方块）,DrawRed（走过站点红色方块）三种方法;

  - **ReadFile()**:负责读取Map.txt站点坐标信息

  - **Draw()**:接收到来自三个button通过ConsoleInterface（）将后端生成的output传递，Draw()处理output的格式并画出路线

  - **接口设计**：

    将后端打包成subway_dll.dll动态链接库，入口函数 ConsoleInterface(int type, ref byte input, ref byte output)传递type和input,接受output

  **Task2运行截图：**

  - 错误输入弹窗：![错误输入弹窗](C:\Users\halfrot\Documents\GitHub\Software-Engineering-Project\blog\assets\错误输入弹窗.png)

  - 线路查询：1号线![line](C:\Users\halfrot\Documents\GitHub\Software-Engineering-Project\blog\assets\line.gif)
  - 最短路查询：![shortest](C:\Users\halfrot\Documents\GitHub\Software-Engineering-Project\blog\assets\shortest.png)

- PSP文档：

  ## PSP表格

  | PSP2.1                                  | Personal Software Process Stages        | 预估耗时（分钟） | 实际耗时（分钟） |
  | :-------------------------------------- | :-------------------------------------- | :--------------: | :--------------: |
  | Planning                                | 计划                                    |        10        |        60        |
  | · Estimate                              | · 估计这个任务需要多少时间              |        10        |       1000       |
  | Development                             | 开发                                    |       500        |       600        |
  | · Analysis                              | · 需求分析 (包括学习新技术)             |        30        |       120        |
  | · Design Spec                           | · 生成设计文档                          |        80        |       360        |
  | · Design Review                         | · 设计复审 (和同事审核设计文档)         |        10        |        60        |
  | · Coding Standard                       | · 代码规范 (为目前的开发制定合适的规范) |        30        |        30        |
  | · Design                                | · 具体设计                              |        60        |        60        |
  | · Coding                                | · 具体编码                              |       170        |       500        |
  | · Code Review                           | · 代码复审                              |        30        |        60        |
  | · Test                                  | · 测试（自我测试，修改代码，提交修改）  |        90        |       100        |
  | Reporting                               | 报告                                    |       120        |       200        |
  | · Test Report                           | · 测试报告                              |        60        |        40        |
  | · Size Measurement                      | · 计算工作量                            |        40        |        20        |
  | · Postmortem & Process Improvement Plan | · 事后总结, 并提出过程改进计划          |        20        |        20        |
  |                                         | 合计                                    |       630        |       3230       |

