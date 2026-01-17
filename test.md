**Preface**
前言

**To Everyone**
致每一个人

Welcome to this book!
欢迎阅读本书！

We hope you'll enjoy reading it as much as we enjoyed writing it.
我们希望您阅读本书的乐趣能像我们撰写本书时一样多。

The book is called **Operating Systems: Three Easy Pieces** (available at [http://ostep.org](http://ostep.org)), and the title is obviously an homage to one of the greatest sets of lecture notes ever created, by one Richard Feynman on the topic of Physics.
本书名为《**操作系统导论**》（**Operating Systems: Three Easy Pieces**，可在 [http://ostep.org](http://ostep.org) 获取），这个标题显然是在向理查德·费曼（Richard Feynman）关于物理学的伟大讲义致敬，那是通过史以来最伟大的讲义之一。

While this book will undoubtedly fall short of the high standard set by that famous physicist, perhaps it will be good enough for you in your quest to understand what operating systems (and more generally, systems) are all about.
虽然本书无疑难以企及那位著名物理学家设立的高标准，但也许它足够帮助您探索操作系统（以及更广泛的系统）的奥秘。

The three easy pieces refer to the three major thematic elements the book is organized around: virtualization, concurrency, and persistence.
这“三个简单的部分”指的是本书围绕组织的三个主要主题元素：虚拟化、并发和持久性。

In discussing these concepts, we'll end up discussing most of the important things an operating system does.
在讨论这些概念时，我们将最终探讨操作系统所做的大部分重要工作。

Hopefully, you'll also have some fun along the way.
希望您在此过程中也能获得一些乐趣。

Learning new things is fun, right?
学习新事物很有趣，对吧？

At least, it (usually) should be.
至少，它（通常）应该是这样的。

Each major concept is divided into a set of chapters, most of which present a particular problem and then show how to solve it.
每个主要概念都分为一组章节，其中大多数章节会提出一个特定问题，然后展示如何解决它。

The chapters are short, and try (as best as possible) to reference the source material where the ideas really came from.
章节都很短，并尽可能地引用思想真正来源的原始资料。

One of our goals in writing this book is to make the paths of history as clear as possible, as we think that helps a student understand what is, what was, and what will be more clearly.
我们要编写这本书的目标之一是尽可能清晰地呈现历史的脉络，因为我们认为这有助于学生更清楚地理解现状、过去和未来。

In this case, seeing how the sausage was made is nearly as important as understanding what the sausage is good for.
在这种情况下，了解“香肠是如何制作的”几乎与了解“香肠有什么用处”一样重要。

Hint: eating!
提示：吃！

Or if you're a vegetarian, running away from..
或者如果您是素食主义者，那就逃离……

There are a couple devices we use throughout the book which are probably worth introducing here.
我们在整本书中使用了一些手段，也许值得在这里介绍一下。

The first is the **crux of the problem**.
第一点是**问题的关键 (crux of the problem)**。

Anytime we are trying to solve a problem, we first try to state what the most important issue is.
每当我们试图解决一个问题时，我们首先尝试陈述最重要的问题是什么。

Such a crux of the problem is explicitly called out in the text, and hopefully solved via the techniques, algorithms, and ideas presented in the rest of the text.
这种“问题的关键”会在文中明确指出，并希望通过文中随后介绍的技术、算法和思想来解决。

In many places, we'll explain how a system works by showing its behavior over time.
在很多地方，我们将通过展示系统随时间变化的行为来解释它是如何工作的。

These timelines are at the essence of understanding; if you know what happens, for example, when a process page faults, you are on your way to truly understanding how virtual memory operates.
这些时间线是理解的本质；例如，如果您知道当进程发生页面错误（page fault）时会发生什么，您就开始真正理解虚拟内存是如何运作的了。

If you comprehend what takes place when a journaling file system writes a block to disk, you have taken the first steps towards mastery of storage systems.
如果您理解当日志文件系统将一个块写入磁盘时发生了什么，您就迈出了精通存储系统的第一步。

There are also numerous asides and tips throughout the text, adding a little color to the mainline presentation.
文中还有许多旁白和提示，为主要内容的陈述增添了一些色彩。

Asides tend to discuss something relevant (but perhaps not essential) to the main text.
旁白倾向于讨论与正文相关（但也许不是必不可少）的内容。

Tips tend to be general lessons that can be applied to systems you build.
提示倾向于通用的经验教训，可应用于您构建的系统。

An index at the end of the book lists all of these tips and asides (as well as cruces, the odd plural of crux) for your convenience.
书末的索引列出了所有这些提示和旁白（以及 cruces，即 crux 的古怪复数形式），以方便您查阅。

We use one of the oldest didactic methods, the dialogue, throughout the book, as a way of presenting some of the material in a different light.
我们在整本书中使用了最古老的教学方法之一——对话，作为以不同角度呈现部分材料的一种方式。

These are used to introduce the major thematic concepts (in a peachy way, as we will see), as well as to review material every now and then.
这些对话用于介绍主要的主题概念（正如我们将看到的，以一种“桃子般”有趣的方式），以及不时地复习材料。

They are also a chance to write in a more humorous style.
这也是一个以更幽默的风格进行写作的机会。

Whether you find them useful, or humorous, well, that's another matter entirely.
无论您觉得它们是有用还是幽默，好吧，那完全是另一回事了。

At the beginning of each major section, we'll first present an abstraction that an operating system provides, and then work in subsequent chapters on the mechanisms, policies, and other support needed to provide the abstraction.
在每个主要部分的开头，我们将首先介绍操作系统提供的一个抽象，然后在随后的章节中研究提供该抽象所需的机制、策略和其他支持。

Abstractions are fundamental to all aspects of Computer Science, so it is perhaps no surprise that they are also essential in operating systems.
抽象是计算机科学各个方面的基础，因此它们在操作系统中也至关重要，这也许不足为奇。

Throughout the chapters, we try to use real code (not pseudocode) where possible, so for virtually all examples, you should be able to type them up yourself and run them.
在整章中，我们尽可能尝试使用真实代码（而不是伪代码），因此对于几乎所有的示例，您应该都能够自己输入并运行它们。

Running real code on real systems is the best way to learn about operating systems, so we encourage you to do so when you can.
在真实系统上运行真实代码是学习操作系统的最佳方式，因此我们鼓励您在可能的情况下这样做。

We are also making code available for your viewing pleasure.
我们还提供了代码供您查阅。

In various parts of the text, we have sprinkled in a few homeworks to ensure that you are understanding what is going on.
在文中的不同部分，我们穿插了一些家庭作业，以确保您理解正在发生的事情。

Many of these homeworks are little simulations of pieces of the operating system.
其中许多作业是操作系统组件的小型模拟。

You should download the homeworks, and run them to quiz yourself.
您应该下载这些作业，并运行它们来测验自己。

The homework simulators have the following feature: by giving them a different random seed, you can generate a virtually infinite set of problems.
这些作业模拟器具有以下特点：通过给它们不同的随机种子，您可以生成几乎无限的一组问题。

The simulators can also be told to solve the problems for you.
这些模拟器也可以被指令为您解决问题。

Thus, you can test and re-test yourself until you have achieved a good level of understanding.
因此，您可以反复测试自己，直到达到良好的理解水平。

The most important addendum to this book is a set of projects in which you learn about how real systems work by designing, implementing, and testing your own code.
本书最重要的附录是一组项目，在这些项目中，您将通过设计、实现和测试自己的代码来了解真实系统是如何工作的。

All projects (as well as the code examples, mentioned above) are in the C programming language.
所有项目（以及上面提到的代码示例）都是用 C 语言编写的。

C is a simple and powerful language that underlies most operating systems, and thus worth adding to your tool-chest of languages.
C 是一种简单而强大的语言，是大多数操作系统的基础，因此值得将其添加到您的语言工具箱中。

Two types of projects are available (see the online appendix for ideas).
有两种类型的项目可供选择（请参阅在线附录以获取思路）。

The first type is systems programming projects.
第一类是系统编程项目。

These projects are great for those who are new to C and UNIX and want to learn how to do low-level C programming.
这些项目非常适合那些刚接触 C 和 UNIX 并想学习如何进行低级 C 编程的人。

The second type is based on a real operating system kernel developed at MIT called **xv6**.
第二类项目基于麻省理工学院（MIT）开发的一个名为 **xv6** 的真实操作系统内核。

These projects are great for students that already have some C and want to get their hands dirty inside the OS.
这些项目非常适合那些已经掌握了一些 C 语言并想深入操作系统内部实践的学生。

At Wisconsin, we've run the course in three different ways: either all systems programming, all xv6 programming, or a mix of both.
在威斯康星大学，我们以三种不同的方式开设这门课程：要么全部是系统编程，要么全部是 xv6 编程，或者是两者的混合。

We are slowly making project descriptions, and a testing framework, available.
我们正在慢慢提供项目说明和测试框架。

See our repository for more information.
请查看我们的代码仓库以获取更多信息。

If not part of a class, this will give you a chance to do these projects on your own, to better learn the material.
如果您不是在参加课程，这将给您一个独自完成这些项目的机会，以便更好地学习材料。

Unfortunately, you don't have a TA to bug when you get stuck, but not everything in life can be free (but books can be!).
遗憾的是，当您卡住时没有助教可以打扰，但生活中并非所有东西都是免费的（但书可以是！）。

**To Educators**
致教育工作者

If you are an instructor or professor who wishes to use this book, please feel free to do so.
如果您是一位希望使用本书的讲师或教授，请随时使用。

As you may have noticed, they are free and available on-line from the following web page: [http://www.ostep.org](http://www.ostep.org)
正如您可能注意到的，它们是免费的，并可从以下网页在线获取：[http://www.ostep.org](http://www.ostep.org)

You can also purchase a printed copy from [http://lulu.com](http://lulu.com) or [http://amazon.com](http://amazon.com).
您也可以从 [http://lulu.com](http://lulu.com) 或 [http://amazon.com](http://amazon.com) 购买纸质版。

The course divides fairly well across a 15-week semester, in which you can cover most of the topics within at a reasonable level of depth.
这门课程可以很好地划分在 15 周的学期中，您可以以合理的深度涵盖其中的大部分主题。

Cramming the course into a 10-week quarter probably requires dropping some detail from each of the pieces.
将课程压缩到 10 周的学期可能需要从每个部分中删减一些细节。

There are also a few chapters on virtual machine monitors, which we usually squeeze in sometime during the semester, either right at end of the large section on virtualization, or near the end as an aside.
还有几章关于虚拟机监视器的内容，我们通常会在学期中的某个时间挤进去讲，要么是在虚拟化这一大章的最后，要么是在接近尾声时作为补充。

One slightly unusual aspect of the book is that concurrency, a topic at the front of many OS books, is pushed off herein until the student has built an understanding of virtualization of the CPU and of memory.
本书一个稍显不同寻常的地方是，并发（许多操作系统书籍开头就会讲的主题）在这里被推迟了，直到学生建立了对 CPU 和内存虚拟化的理解之后才讲。

In our experience in teaching this course for nearly 20 years, students have a hard time understanding how the concurrency problem arises, or why they are trying to solve it, if they don't yet understand what an address space is, what a process is, or why context switches can occur at arbitrary points in time.
根据我们要讲授这门课程近 20 年的经验，如果学生还不理解什么是地址空间、什么是进程，或者为什么上下文切换可能在任意时间点发生，他们就很难理解并发问题是如何产生的，或者为什么要试图解决它。

Once they do understand these concepts, however, introducing the notion of threads and the problems that arise due to them becomes rather easy, or at least, easier.
然而，一旦他们理解了这些概念，引入线程的概念以及由此产生的问题就变得相当容易，或者至少更容易了。

As much as is possible, we use a chalkboard (or whiteboard) to deliver a lecture.
我们要尽可能使用黑板（或白板）来讲课。

On these more conceptual days, we come to class with a few major ideas and examples in mind and use the board to present them.
在讲解这些概念性较强的日子里，我们会带着几个主要观点和例子来上课，并用黑板来演示它们。

Handouts are useful to give the students concrete problems to solve based on the material.
讲义对于给学生提供基于材料的具体问题来解决很有用。

On more practical days, we simply plug a laptop into the projector and show real code.
在讲解实践性较强的日子里，我们只需将笔记本电脑连接到投影仪上并展示真实代码。

This style works particularly well for concurrency lectures as well as for any discussion sections where you show students code that is relevant for their projects.
这种风格特别适合并发课程，以及任何向学生展示与其项目相关的代码的讨论环节。

We don't generally use slides to present material, but have now made a set available for those who prefer that style of presentation.
我们通常不使用幻灯片来展示材料，但现在已经为那些喜欢这种展示风格的人提供了一套幻灯片。

If you'd like a copy of any of these materials, please drop us an email.
如果您想要这些材料的副本，请给我们发电子邮件。

One last request: if you use the free online chapters, please just link to them, instead of making a local copy.
最后一个请求：如果您使用免费的在线章节，请直接链接到它们，而不是制作本地副本。

This helps us track usage (million of chapters downloaded each month) and also ensures students get the latest (and greatest?) version.
这有助于我们跟踪使用情况（每月数百万章的下载量），并确保学生获得最新（也是最好？）的版本。

**To Students**
致学生

If you are a student reading this book, thank you!
如果您是正在阅读本书的学生，谢谢您！

It is an honor for us to provide some material to help you in your pursuit of knowledge about operating systems.
我们很荣幸能提供一些材料，帮助您追求关于操作系统的知识。

We both think back fondly towards some textbooks of our undergraduate days (e.g., Hennessy and Patterson, the classic book on computer architecture) and hope this book will become one of those positive memories for you.
我们要深情地回想起我们本科时代的一些教科书（例如，Hennessy 和 Patterson 编写的关于计算机体系结构的经典著作），并希望这本书能成为您美好回忆的一部分。

You may have noticed this book is free and available online.
您可能已经注意到这本书是免费的，并且可以在线获取。

There is one major reason for this: textbooks are generally too expensive.
这其中有一个主要原因：教科书通常太贵了。

This book, we hope, is the first of a new wave of free materials to help those in pursuit of their education, regardless of which part of the world they come from or how much they are willing to spend for a book.
我们希望这本书能成为新一波免费教材的先驱，帮助那些追求教育的人，无论他们来自世界的哪个角落，也无论他们愿意为一本书花多少钱。

Failing that, it is one free book, which is better than none.
即便做不到这一点，这也算是一本免费的书，总比没有好。

We also hope, where possible, to point you to the original sources of much of the material in the book: the great papers and persons who have shaped the field of operating systems over the years.
我们还希望在可能的情况下，向您指出书中大部分材料的原始来源：那些多年来塑造了操作系统领域的伟大论文和人物。

Ideas are not pulled out of the air; they come from smart and hard-working people (including numerous Turing-award winners), and thus we should strive to celebrate those ideas and people where possible.
思想不是凭空产生的；它们来自聪明和勤奋的人（包括许多图灵奖得主），因此我们应该尽可能地赞美这些思想和人物。

In doing so, we hopefully can better understand the revolutions that have taken place, instead of writing texts as if those thoughts have always been present.
这样做，我们希望能更好地理解已经发生的革命，而不是把教科书写得好像这些思想一直存在一样。

Further, perhaps such references will encourage you to dig deeper on your own.
此外，也许这些参考文献会鼓励您自己进行更深入的挖掘。

Reading the famous papers of our field is certainly one of the best ways to learn.
阅读我们领域的著名论文无疑是最好的学习方式之一。

A digression here: "free" in the way we use it here does not mean open source, and it does not mean the book is not copyrighted with the usual protections - it is!
这里离题一下：我们在这里使用的“免费”并不意味着开源，也不意味着这本书没有受到通常的版权保护——它受保护！

What it means is that you can download the chapters and use them to learn about operating systems.
它的意思是您可以下载章节并使用它们来学习操作系统。

Why not an open-source book, just like Linux is an open-source kernel?
为什么不像 Linux 是开源内核那样做一本开源书呢？

Well, we believe it is important for a book to have a single voice throughout, and have worked hard to provide such a voice.
好吧，我们认为一本书在通篇保持统一的声音很重要，并且我们一直在努力提供这样的声音。

When you're reading it, the book should kind of feel like a dialogue with the person explaining something to you.
当您阅读它时，这本书应该感觉像是与向您解释某事的人进行的对话。

Hence, our approach.
因此，我们要采取了这种方法。

The Turing Award is the highest award in Computer Science; it is like the Nobel Prize, except that you have never heard of it.
图灵奖是计算机科学的最高奖项；它就像诺贝尔奖，除了您可能从未听说过它。

**Acknowledgments**
致谢

This section will contain thanks to those who helped us put the book together.
本节将包含对那些帮助我们编写本书的人的感谢。

The important thing for now: your name could go here!
现在重要的是：您的名字可能会出现在这里！

But, you have to help.
但是，您得提供帮助。

So send us some feedback and help debug this book.
所以给我们发送一些反馈，帮助调试这本书。

And you could be famous!
您可能会出名！

Or, at least, have your name in some book.
或者，至少，您的名字会出现在某本书里。

The people who have helped so far include:
到目前为止提供帮助的人包括：（以下为大量人名，此处保留原文以示尊重）
Aaron Gember, Aashrith H Govindraj, Abdallah Ahmed, Abhinav Mehra, ... (and hundreds more students and contributors).

Special thanks to those marked with an asterisk above, who have gone above and beyond in their suggestions for improvement.
特别感谢上面标有星号的人，他们在提出改进建议方面付出了额外的努力。

In addition, a hearty thanks to Professor Joe Meehean (Lynchburg) for his detailed notes on each chapter.
此外，衷心感谢 Joe Meehean 教授（Lynchburg）为每一章提供的详细笔记。

To Professor Jerod Weinman (Grinnell) and his entire class for their incredible booklets.
感谢 Jerod Weinman 教授（Grinnell）和他全班同学制作的令人难以置信的小册子。

To Professor Chien-Chung Shen (Delaware) for his invaluable and detailed reading and comments.
感谢 Chien-Chung Shen 教授（特拉华大学）提供的宝贵而详细的阅读和评论。

To Adam Drescher (WUSTL) for his careful reading and suggestions.
感谢 Adam Drescher (WUSTL) 的仔细阅读和建议。

To Glen Granzow (College of Idaho) for his incredibly detailed comments and tips.
感谢 Glen Granzow（爱达荷学院）提供的极其详细的评论和提示。

To Michael Walfish (NYU) for his enthusiasm and detailed suggestions for improvement.
感谢 Michael Walfish (NYU) 的热情和详细的改进建议。

To Peter Peterson (UMD) for his many bits of useful feedback and commentary.
感谢 Peter Peterson (UMD) 提供的许多有用的反馈和评论。

To Mark Kampe (Pomona) for detailed criticism (we only wish we could fix all suggestions!).
感谢 Mark Kampe (Pomona) 的详细批评（我们只希望我们能修正所有的建议！）。

And to Youjip Won (Hanyang) for his translation work into Korean(!) and numerous insightful suggestions.
感谢 Youjip Won (汉阳大学) 将本书翻译成韩语（！）以及无数富有洞察力的建议。

To Terence Kelly for his sidebar on memory mapping.
感谢 Terence Kelly 关于内存映射的侧边栏内容。

All have helped these authors immeasurably in the refinement of the materials herein.
所有这些人都对作者完善本书材料提供了不可估量的帮助。

A special thank you to Professor Peter Reiher (UCLA) for writing a wonderful set of security chapters, all in the style of this book.
特别感谢 Peter Reiher 教授（UCLA）撰写了一套精彩的安全章节，风格与本书完全一致。

We had the fortune of meeting Peter many years ago, and little did we know that we would collaborate in this fashion two decades later.
我们有幸在许多年前遇到了 Peter，当时完全没想到二十年后我们会以这种方式合作。

Amazing work!
了不起的工作！

Also, many thanks to the hundreds of students who have taken 537 over the years.
此外，非常感谢多年来选修 537 课程的数百名学生。

In particular, the Fall '08 class who encouraged the first written form of these notes (they were sick of not having any kind of textbook to read pushy students!), and then praised them enough for us to keep going.
特别是 08 年秋季班的学生，他们鼓励了这些笔记的最初书面形式（他们厌倦了没有任何教科书可读——爱催促的学生！），然后给予了足够的赞扬让我们坚持下去。

A great debt of thanks is also owed to the brave few who took the xv6 project lab course, much of which is now incorporated into the main 537 course.
还要非常感谢那些参加 xv6 项目实验课程的勇敢的少数人，其中大部分内容现在已并入主要的 537 课程中。

Although they do not directly help with the book, our students have taught us much of what we know about systems.
虽然他们不直接帮助编写本书，但我们的学生教会了我们许多关于系统的知识。

We talk with them regularly while they are at Wisconsin, but they do all the real work and by telling us about what they are doing, we learn new things every week.
当他们在威斯康星大学时，我们要定期与他们交谈，但他们做了所有实际的工作，通过告诉我们他们在做什么，我们每周都能学到新东西。

Our graduate students have largely been funded by the National Science Foundation (NSF), the Department of Energy Office of Science (DOE), and by industry grants.
我们的研究生主要由国家科学基金会 (NSF)、能源部科学办公室 (DOE) 和行业资助。

We are especially grateful to the NSF for their support over many years, as our research has shaped the content of many chapters herein.
我们要特别感谢 NSF 多年来的支持，因为我们的研究塑造了本书许多章节的内容。

We thank Thomas Griebel, who demanded a better cover for the book.
我们感谢 Thomas Griebel，他要求这本书有一个更好的封面。

Although we didn't take his specific suggestion (a dinosaur, can you believe it?), the beautiful picture of Halley's comet would not be found on the cover without him.
虽然我们要没有采纳他的具体建议（一只恐龙，你敢信？），但如果没有他，封面上就不会有哈雷彗星的美丽照片。

A final debt of gratitude is also owed to Aaron Brown.
最后还要感谢 Aaron Brown。

His tireless work has vastly improved the state of the projects (particularly those in xv6 land) and thus has helped better the learning experience for countless undergraduates and graduates here at Wisconsin.
他不懈的工作极大地改善了项目的状况（特别是在 xv6 领域），从而帮助改善了威斯康星大学无数本科生和研究生的学习体验。

As Aaron would say (in his usual succinct manner): "Thx."
正如 Aaron 会说的那样（以他一贯简洁的方式）：“谢了。”

**Final Words**
最后的话

Yeats famously said "Education is not the filling of a pail but the lighting of a fire."
叶芝有句名言：“教育不是注满一桶水，而是点燃一把火。”

He was right but wrong at the same time.
他是对的，但同时也错了。

You do have to "fill the pail" a bit, and these notes are certainly here to help with that part of your education.
你确实需要“注满桶”一点，而这些笔记当然是为了帮助你完成那部分教育；

After all, when you go to interview at Google, and they ask you a trick question about how to use semaphores, it might be good to actually know what a semaphore is, right?
毕竟，当你去 Google 面试时，如果他们问你一个关于如何使用信号量的刁钻问题，真正知道信号量是什么可能会很好，对吧？

But Yeats's larger point is obviously on the mark: the real point of education is to get you interested in something, to learn something more about the subject matter on your own and not just what you have to digest to get a good grade in some class.
但叶芝更宏大的观点显然是正确的：教育的真正意义在于让你对某事感兴趣，让你自己去学习更多关于该主题的知识，而不仅仅是为了在某门课上取得好成绩而必须消化的东西。

As one of our fathers (Remzi's dad, Vedat Arpaci) used to say, "Learn beyond the classroom".
正如我们要的一位父亲（Remzi 的父亲，Vedat Arpaci）常说的，“要在课堂之外学习”。

We created these notes to spark your interest in operating systems, to read more about the topic on your own, to talk to your professor about all the exciting research that is going on in the field, and even to get involved with that research.
我们创建这些笔记是为了激发您对操作系统的兴趣，让您自己阅读更多关于该主题的内容，与您的教授谈论该领域正在进行的所有令人兴奋的研究，甚至参与到该研究中去。

It is a great field(!), full of exciting and wonderful ideas that have shaped computing history in profound and important ways.
这是一个伟大的领域（！），充满了令人兴奋和奇妙的思想，这些思想以深刻而重要的方式塑造了计算历史。

And while we understand this fire won't light for all of you, we hope it does for many, or even a few.
虽然我们要明白这把火不会为你们所有人点燃，但我们希望它能为许多人，甚至只是少数人点燃。

Because once that fire is lit, well, that is when you truly become capable of doing something great.
因为一旦这把火被点燃，那么，那正是你真正有能力做一些伟大的事情的时候。

And thus the real point of the educational process: to go forth, to study many new and fascinating topics, to learn, to mature, and most importantly, to find something that lights a fire for you.
这就是教育过程的真正意义：勇往直前，研究许多新颖而迷人的话题，学习，成熟，最重要的是，找到能为你点燃心中之火的东西。

Andrea and Remzi
Andrea 和 Remzi

Married couple
已婚夫妇

Professors of Computer Science at the University of Wisconsin
威斯康星大学计算机科学教授

Chief Lighters of Fires, hopefully
希望能成为首席点火人

**References**
参考文献

[CK+08] "The xv6 Operating System" by Russ Cox, Frans Kaashoek, Robert Morris, Nickolai Zeldovich.
[CK+08] 《xv6 操作系统》，作者：Russ Cox, Frans Kaashoek, Robert Morris, Nickolai Zeldovich。

xv6 was developed as a port of the original UNIX version 6 and represents a beautiful, clean, and simple way to understand a modern operating system.
xv6 是作为原始 UNIX 第 6 版的移植版开发的，代表了一种理解现代操作系统的优美、干净且简单的方式。

[F96] "Six Easy Pieces: Essentials Of Physics Explained By Its Most Brilliant Teacher" by Richard P. Feynman.
[F96] 《物理之美：费曼物理学讲义入门选》（Six Easy Pieces），作者：Richard P. Feynman。

Basic Books, 1996. This book reprints the six easiest chapters of Feynman's Lectures on Physics, from 1963.
Basic Books 出版社，1996 年。本书重印了 1963 年《费曼物理学讲义》中最简单的六章。

If you like Physics, it is a fantastic read.
如果您喜欢物理，这是一本极好的读物。

[HP90] "Computer Architecture a Quantitative Approach" (1st ed.) by David A. Patterson and John L. Hennessy.
[HP90] 《计算机体系结构：量化研究方法》（第 1 版），作者：David A. Patterson 和 John L. Hennessy。

A book that encouraged each of us at our undergraduate institutions to pursue graduate studies.
这是一本鼓励我们在本科院校攻读研究生的书。

We later both had the pleasure of working with Patterson, who greatly shaped the foundations of our research careers.
我们要后来都有幸与 Patterson 共事，他极大地塑造了我们研究生涯的基础。

[KR88] "The C Programming Language" by Brian Kernighan and Dennis Ritchie.
[KR88] 《C 程序设计语言》，作者：Brian Kernighan 和 Dennis Ritchie。

The C programming reference that everyone should have, by the people who invented the language.
每个人都应该拥有的 C 编程参考书，由发明该语言的人编写。

[K62] "The Structure of Scientific Revolutions" by Thomas S. Kuhn.
[K62] 《科学革命的结构》，作者：Thomas S. Kuhn。

A great and famous read about the fundamentals of the scientific process.
关于科学过程基础的一本伟大而著名的读物。

Mop-up work, anomaly, crisis, and revolution.
扫尾工作、反常、危机和革命。

We are mostly destined to do mop-up work, alas.
唉，我们大多数人注定要做扫尾工作。

**Contents**
目录

1 A Dialogue on the Book
1 关于本书的对话

2 Introduction to Operating Systems
2 操作系统介绍

2.1 Virtualizing The CPU
2.1 CPU 虚拟化

2.2 Virtualizing Memory
2.2 内存虚拟化

2.3 Concurrency
2.3 并发

2.4 Persistence
2.4 持久性

2.5 Design Goals
2.5 设计目标

2.6 Some History
2.6 一些历史

2.7 Summary
2.7 总结

**Part I: Virtualization**
**第一部分：虚拟化**

3 A Dialogue on Virtualization
3 关于虚拟化的对话

4 The Abstraction: The Process
4 抽象：进程

4.1 The Abstraction: A Process
4.1 抽象：一个进程

4.2 Process API
4.2 进程 API

4.3 Process Creation: A Little More Detail
4.3 进程创建：更多细节

4.4 Process States
4.4 进程状态

4.5 Data Structures
4.5 数据结构

4.6 Summary
4.6 总结

5 Interlude: Process API
5 插曲：进程 API

5.1 The fork() System Call
5.1 fork() 系统调用

5.2 The wait() System Call
5.2 wait() 系统调用

5.3 Finally, The exec() System Call
5.3 最后，exec() 系统调用

5.4 Why? Motivating The API
5.4 为什么？API 的动机

5.5 Process Control And Users
5.5 进程控制与用户

5.6 Useful Tools
5.6 有用的工具

5.7 Summary
5.7 总结

6 Mechanism: Limited Direct Execution
6 机制：受限直接执行

6.1 Basic Technique: Limited Direct Execution
6.1 基本技术：受限直接执行

6.2 Problem #1: Restricted Operations
6.2 问题 #1：受限操作

6.3 Problem #2: Switching Between Processes
6.3 问题 #2：在进程间切换

6.4 Worried About Concurrency?
6.4 担心并发？

6.5 Summary
6.5 总结

7 Scheduling: Introduction
7 调度：简介

7.1 Workload Assumptions
7.1 工作负载假设

7.2 Scheduling Metrics
7.2 调度指标

7.3 First In, First Out (FIFO)
7.3 先进先出 (FIFO)

7.4 Shortest Job First (SJF)
7.4 最短任务优先 (SJF)

7.5 Shortest Time-to-Completion First (STCF)
7.5 最短完成时间优先 (STCF)

7.6 A New Metric: Response Time
7.6 一个新指标：响应时间

7.7 Round Robin
7.7 轮转调度 (Round Robin)

7.8 Incorporating I/O
7.8 结合 I/O

7.9 No More Oracle
7.9 不再有预言机

7.10 Summary
7.10 总结

8 Scheduling: The Multi-Level Feedback Queue
8 调度：多级反馈队列

8.1 MLFQ: Basic Rules
8.1 MLFQ：基本规则

8.2 Attempt #1: How To Change Priority
8.2 尝试 #1：如何改变优先级

8.3 Attempt #2: The Priority Boost
8.3 尝试 #2：优先级提升

8.4 Attempt #3: Better Accounting
8.4 尝试 #3：更好的计时

8.5 Tuning MLFQ And Other Issues
8.5 调优 MLFQ 及其他问题

8.6 MLFQ: Summary
8.6 MLFQ：总结

9 Scheduling: Proportional Share
9 调度：比例份额

9.1 Basic Concept: Tickets Represent Your Share
9.1 基本概念：彩票代表你的份额

9.2 Ticket Mechanisms
9.2 彩票机制

9.3 Implementation
9.3 实现

9.4 An Example
9.4 一个例子

9.5 How To Assign Tickets?
9.5 如何分配彩票？

9.6 Stride Scheduling
9.6 步长调度

9.7 The Linux Completely Fair Scheduler (CFS)
9.7 Linux 完全公平调度器 (CFS)

9.8 Summary
9.8 总结

10 Multiprocessor Scheduling (Advanced)
10 多处理器调度（进阶）

10.1 Background: Multiprocessor Architecture
10.1 背景：多处理器架构

10.2 Don't Forget Synchronization
10.2 别忘了同步

10.3 One Final Issue: Cache Affinity
10.3 最后一个问题：缓存亲和性

10.4 Single-Queue Scheduling
10.4 单队列调度

10.5 Multi-Queue Scheduling
10.5 多队列调度

10.6 Linux Multiprocessor Schedulers
10.6 Linux 多处理器调度器

10.7 Summary
10.7 总结

11 Summary Dialogue on CPU Virtualization
11 关于 CPU 虚拟化的总结对话

12 A Dialogue on Memory Virtualization
12 关于内存虚拟化的对话

13 The Abstraction: Address Spaces
13 抽象：地址空间

13.1 Early Systems
13.1 早期系统

13.2 Multiprogramming and Time Sharing
13.2 多道程序设计和分时

13.3 The Address Space
13.3 地址空间

13.4 Goals
13.4 目标

13.5 Summary
13.5 总结

14 Interlude: Memory API
14 插曲：内存 API

14.1 Types of Memory
14.1 内存类型

14.2 The malloc() Call
14.2 malloc() 调用

14.3 The free() Call
14.3 free() 调用

14.4 Common Errors
14.4 常见错误

14.5 Underlying OS Support
14.5 底层操作系统支持

14.6 Other Calls
14.6 其他调用

14.7 Summary
14.7 总结

15 Mechanism: Address Translation
15 机制：地址转换

15.1 Assumptions
15.1 假设

15.2 An Example
15.2 一个例子

15.3 Dynamic (Hardware-based) Relocation
15.3 动态（基于硬件的）重定位

15.4 Hardware Support: A Summary
15.4 硬件支持：总结

15.5 Operating System Issues
15.5 操作系统问题

15.6 Summary
15.6 总结

16 Segmentation
16 分段

16.1 Segmentation: Generalized Base/Bounds
16.1 分段：广义的基址/界限

16.2 Which Segment Are We Referring To?
16.2 我们指的是哪个段？

16.3 What About The Stack?
16.3 栈怎么办？

16.4 Support for Sharing
16.4 支持共享

16.5 Fine-grained vs. Coarse-grained Segmentation
16.5 细粒度与粗粒度分段

16.6 OS Support
16.6 操作系统支持

16.7 Summary
16.7 总结

17 Free-Space Management
17 空闲空间管理

17.1 Assumptions
17.1 假设

17.2 Low-level Mechanisms
17.2 低级机制

17.3 Basic Strategies
17.3 基本策略

17.4 Other Approaches
17.4 其他方法

17.5 Summary
17.5 总结

18 Paging: Introduction
18 分页：简介

18.1 A Simple Example And Overview
18.1 简单示例与概述

18.2 Where Are Page Tables Stored?
18.2 页表存在哪里？

18.3 What's Actually In The Page Table?
18.3 页表里实际上有什么？

18.4 Paging: Also Too Slow
18.4 分页：也太慢了

18.5 A Memory Trace
18.5 内存追踪

18.6 Summary
18.6 总结

19 Paging: Faster Translations (TLBs)
19 分页：更快的转换 (TLB)

19.1 TLB Basic Algorithm
19.1 TLB 基本算法

19.2 Example: Accessing An Array
19.2 示例：访问数组

19.3 Who Handles The TLB Miss?
19.3 谁来处理 TLB 未命中？

19.4 TLB Contents: What's In There?
19.4 TLB 内容：里面有什么？

19.5 TLB Issue: Context Switches
19.5 TLB 问题：上下文切换

19.6 Issue: Replacement Policy
19.6 问题：替换策略

19.7 A Real TLB Entry
19.7 真实的 TLB 表项

19.8 Summary
19.8 总结

20 Paging: Smaller Tables
20 分页：更小的表

20.1 Simple Solution: Bigger Pages
20.1 简单的解决方案：更大的页面

20.2 Hybrid Approach: Paging and Segments
20.2 混合方法：分页和分段

20.3 Multi-level Page Tables
20.3 多级页表

20.4 Inverted Page Tables
20.4 反向页表

20.5 Swapping the Page Tables to Disk
20.5 将页表交换到磁盘

20.6 Summary
20.6 总结

21 Beyond Physical Memory: Mechanisms
21 超越物理内存：机制

21.1 Swap Space
21.1 交换空间

21.2 The Present Bit
21.2 存在位 (Present Bit)

21.3 The Page Fault
21.3 页面错误 (Page Fault)

21.4 What If Memory Is Full?
21.4 如果内存满了怎么办？

21.5 Page Fault Control Flow
21.5 页面错误控制流

21.6 When Replacements Really Occur
21.6 替换真正发生的时间

21.7 Summary
21.7 总结

22 Beyond Physical Memory: Policies
22 超越物理内存：策略

22.1 Cache Management
22.1 缓存管理

22.2 The Optimal Replacement Policy
22.2 最佳替换策略

22.3 A Simple Policy: FIFO
22.3 一个简单的策略：先进先出 (FIFO)

22.4 Another Simple Policy: Random
22.4 另一个简单的策略：随机

22.5 Using History: LRU
22.5 利用历史记录：最近最少使用 (LRU)

22.6 Workload Examples
22.6 工作负载示例

22.7 Implementing Historical Algorithms
22.7 实现基于历史的算法

22.8 Approximating LRU
22.8 近似 LRU

22.9 Considering Dirty Pages
22.9 考虑脏页

22.10 Other VM Policies
22.10 其他虚拟内存策略

22.11 Thrashing
22.11 抖动 (Thrashing)

22.12 Summary
22.12 总结

23 Complete Virtual Memory Systems
23 完整的虚拟内存系统

23.1 VAX/VMS Virtual Memory
23.1 VAX/VMS 虚拟内存

23.2 The Linux Virtual Memory System
23.2 Linux 虚拟内存系统

23.3 Summary
23.3 总结

24 Summary Dialogue on Memory Virtualization
24 关于内存虚拟化的总结对话

**Part II: Concurrency**
**第二部分：并发**

25 A Dialogue on Concurrency
25 关于并发的对话

26 Concurrency: An Introduction
26 并发：简介

26.1 Why Use Threads?
26.1 为什么要使用线程？

26.2 An Example: Thread Creation
26.2 一个例子：线程创建

26.3 Why It Gets Worse: Shared Data
26.3 为什么情况会变糟：共享数据

26.4 The Heart Of The Problem: Uncontrolled Scheduling
26.4 问题的核心：不受控制的调度

26.5 The Wish For Atomicity
26.5 对原子性的渴望

26.6 One More Problem: Waiting For Another
26.6 另一个问题：等待另一个线程

26.7 Summary: Why in OS Class?
26.7 总结：为什么要在操作系统课上讲？

27 Interlude: Thread API
27 插曲：线程 API

27.1 Thread Creation
27.1 线程创建

27.2 Thread Completion
27.2 线程完成

27.3 Locks
27.3 锁

27.4 Condition Variables
27.4 条件变量

27.5 Compiling and Running
27.5 编译和运行

27.6 Summary
27.6 总结

28 Locks
28 锁

28.1 Locks: The Basic Idea
28.1 锁：基本思想

28.2 Pthread Locks
28.2 Pthread 锁

28.3 Building A Lock
28.3 构建锁

28.4 Evaluating Locks
28.4 评估锁

28.5 Controlling Interrupts
28.5 控制中断

28.6 A Failed Attempt: Just Using Loads/Stores
28.6 一次失败的尝试：仅使用加载/存储

28.7 Building Working Spin Locks with Test-And-Set
28.7 使用测试并设置 (Test-And-Set) 构建工作的自旋锁

28.8 Evaluating Spin Locks
28.8 评估自旋锁

28.9 Compare-And-Swap
28.9 比较并交换 (Compare-And-Swap)

28.10 Load-Linked and Store-Conditional
28.10 链接加载和条件存储 (Load-Linked and Store-Conditional)

28.11 Fetch-And-Add
28.11 获取并增加 (Fetch-And-Add)

28.12 Too Much Spinning: What Now?
28.12 自旋过多：现在怎么办？

28.13 A Simple Approach: Just Yield, Baby
28.13 一个简单的方法：让出 CPU

28.14 Using Queues: Sleeping Instead Of Spinning
28.14 使用队列：休眠代替自旋

28.15 Different OS, Different Support
28.15 不同的操作系统，不同的支持

28.16 Two-Phase Locks
28.16 两阶段锁

28.17 Summary
28.17 总结

29 Lock-based Concurrent Data Structures
29 基于锁的并发数据结构

29.1 Concurrent Counters
29.1 并发计数器

29.2 Concurrent Linked Lists
29.2 并发链表

29.3 Concurrent Queues
29.3 并发队列

29.4 Concurrent Hash Table
29.4 并发哈希表

29.5 Summary
29.5 总结

30 Condition Variables
30 条件变量

30.1 Definition and Routines
30.1 定义和例程

30.2 The Producer/Consumer (Bounded Buffer) Problem
30.2 生产者/消费者（有界缓冲区）问题

30.3 Covering Conditions
30.3 覆盖条件

30.4 Summary
30.4 总结

31 Semaphores
31 信号量

31.1 Semaphores: A Definition
31.1 信号量：定义

31.2 Binary Semaphores (Locks)
31.2 二值信号量（锁）

31.3 Semaphores For Ordering
31.3 用于排序的信号量

31.4 The Producer/Consumer (Bounded Buffer) Problem
31.4 生产者/消费者（有界缓冲区）问题

31.5 Reader-Writer Locks
31.5 读写锁

31.6 The Dining Philosophers
31.6 哲学家就餐问题

31.7 Thread Throttling
31.7 线程限流

31.8 How To Implement Semaphores
31.8 如何实现信号量

31.9 Summary
31.9 总结

32 Common Concurrency Problems
32 常见的并发问题

32.1 What Types Of Bugs Exist?
32.1 存在哪些类型的 Bug？

32.2 Non-Deadlock Bugs
32.2 非死锁 Bug

32.3 Deadlock Bugs
32.3 死锁 Bug

32.4 Summary
32.4 总结

33 Event-based Concurrency (Advanced)
33 基于事件的并发（进阶）

33.1 The Basic Idea: An Event Loop
33.1 基本思想：事件循环

33.2 An Important API: select() (or poll())
33.2 一个重要的 API：select()（或 poll()）

33.3 Using select()
33.3 使用 select()

33.4 Why Simpler? No Locks Needed
33.4 为什么更简单？不需要锁

33.5 A Problem: Blocking System Calls
33.5 一个问题：阻塞系统调用

33.6 A Solution: Asynchronous I/O
33.6 解决方案：异步 I/O

33.7 Another Problem: State Management
33.7 另一个问题：状态管理

33.8 What Is Still Difficult With Events
33.8 事件驱动还有什么困难

33.9 Summary
33.9 总结

34 Summary Dialogue on Concurrency
34 关于并发的总结对话

**Part III: Persistence**
**第三部分：持久性**

35 A Dialogue on Persistence
35 关于持久性的对话

36 I/O Devices
36 I/O 设备

36.1 System Architecture
36.1 系统架构

36.2 A Canonical Device
36.2 典型设备

36.3 The Canonical Protocol
36.3 典型协议

36.4 Lowering CPU Overhead With Interrupts
36.4 使用中断降低 CPU 开销

36.5 More Efficient Data Movement With DMA
36.5 使用 DMA 进行更高效的数据移动

36.6 Methods Of Device Interaction
36.6 设备交互方法

36.7 Fitting Into The OS: The Device Driver
36.7 融入操作系统：设备驱动程序

36.8 Case Study: A Simple IDE Disk Driver
36.8 案例研究：一个简单的 IDE 磁盘驱动程序

36.9 Historical Notes
36.9 历史记录

36.10 Summary
36.10 总结

37 Hard Disk Drives
37 硬盘驱动器

37.1 The Interface
37.1 接口

37.2 Basic Geometry
37.2 基本几何结构

37.3 A Simple Disk Drive
37.3 一个简单的磁盘驱动器

37.4 I/O Time: Doing The Math
37.4 I/O 时间：数学计算

37.5 Disk Scheduling
37.5 磁盘调度

37.6 Summary
37.6 总结

38 Redundant Arrays of Inexpensive Disks (RAIDs)
38 廉价磁盘冗余阵列 (RAID)

38.1 Interface And RAID Internals
38.1 接口和 RAID 内部结构

38.2 Fault Model
38.2 故障模型

38.3 How To Evaluate A RAID
38.3 如何评估 RAID

38.4 RAID Level 0: Striping
38.4 RAID 0 级：条带化

38.5 RAID Level 1: Mirroring
38.5 RAID 1 级：镜像

38.6 RAID Level 4: Saving Space With Parity
38.6 RAID 4 级：使用奇偶校验节省空间

38.7 RAID Level 5: Rotating Parity
38.7 RAID 5 级：旋转奇偶校验

38.8 RAID Comparison: A Summary
38.8 RAID 比较：总结

38.9 Other Interesting RAID Issues
38.9 其他有趣的 RAID 问题

38.10 Summary
38.10 总结

**39 Interlude: Files and Directories**
39 插曲：文件和目录

39.1 Files And Directories
39.1 文件和目录

39.2 The File System Interface
39.2 文件系统接口

39.3 Creating Files
39.3 创建文件

39.4 Reading And Writing Files
39.4 读写文件

39.5 Reading And Writing, But Not Sequentially
39.5 读写，但非顺序

39.6 Shared File Table Entries: fork() And dup()
39.6 共享文件表项：fork() 和 dup()

39.7 Writing Immediately With fsync()
39.7 使用 fsync() 立即写入

39.8 Renaming Files
39.8 重命名文件

39.9 Getting Information About Files
39.9 获取文件信息

39.10 Removing Files
39.10 删除文件

39.11 Making Directories
39.11 创建目录

39.12 Reading Directories
39.12 读取目录

39.13 Deleting Directories
39.13 删除目录

39.14 Hard Links
39.14 硬链接

39.15 Symbolic Links
39.15 符号链接

39.16 Permission Bits And Access Control Lists
39.16 权限位和访问控制列表

39.17 Making And Mounting A File System
39.17 创建和挂载文件系统

39.18 Summary
39.18 总结

**40 File System Implementation**
40 文件系统实现

40.1 The Way To Think
40.1 思考方式

40.2 Overall Organization
40.2 整体组织结构

40.3 File Organization: The Inode
40.3 文件组织：索引节点 (Inode)

40.4 Directory Organization
40.4 目录组织

40.5 Free Space Management
40.5 空闲空间管理

40.6 Access Paths: Reading and Writing
40.6 访问路径：读和写

40.7 Caching and Buffering
40.7 缓存和缓冲

40.8 Summary
40.8 总结

**41 Locality and The Fast File System**
41 局部性和快速文件系统 (FFS)

41.1 The Problem: Poor Performance
41.1 问题：性能不佳

41.2 FFS: Disk Awareness Is The Solution
41.2 FFS：磁盘感知是解决方案

41.3 Organizing Structure: The Cylinder Group
41.3 组织结构：柱面组

41.4 Policies: How To Allocate Files and Directories
41.4 策略：如何分配文件和目录

41.5 Measuring File Locality
41.5 测量文件局部性

41.6 The Large-File Exception
41.6 大文件例外

41.7 A Few Other Things About FFS
41.7 关于 FFS 的其他几件事

41.8 Summary
41.8 总结

**42 Crash Consistency: FSCK and Journaling**
42 崩溃一致性：FSCK 和日志记录

42.1 A Detailed Example
42.1 一个详细的例子

42.2 Solution #1: The File System Checker
42.2 解决方案 #1：文件系统检查器

42.3 Solution #2: Journaling (or Write-Ahead Logging)
42.3 解决方案 #2：日志记录（或预写日志）

42.4 Solution #3: Other Approaches
42.4 解决方案 #3：其他方法

42.5 Summary
42.5 总结

**43 Log-structured File Systems**
43 日志结构文件系统 (LFS)

43.1 Writing To Disk Sequentially
43.1 顺序写入磁盘

43.2 Writing Sequentially And Effectively
43.2 有效地顺序写入

43.3 How Much To Buffer?
43.3 缓冲多少？

43.4 Problem: Finding Inodes
43.4 问题：查找索引节点

43.5 Solution Through Indirection: The Inode Map
43.5 通过间接解决：索引节点映射 (Inode Map)

43.6 Completing The Solution: The Checkpoint Region
43.6 完善解决方案：检查点区域 (Checkpoint Region)

43.7 Reading A File From Disk: A Recap
43.7 从磁盘读取文件：回顾

43.8 What About Directories?
43.8 目录怎么办？

43.9 A New Problem: Garbage Collection
43.9 一个新问题：垃圾回收

43.10 Determining Block Liveness
43.10 确定块的活跃度

43.11 A Policy Question: Which Blocks To Clean, And When?
43.11 一个策略问题：清理哪些块，以及何时清理？

43.12 Crash Recovery And The Log
43.12 崩溃恢复和日志

43.13 Summary
43.13 总结

**44 Flash-based SSDs**
44 基于闪存的 SSD

44.1 Storing a Single Bit
44.1 存储单个位

44.2 From Bits to Banks/Planes
44.2 从位到 Bank/Plane

44.3 Basic Flash Operations
44.3 基本闪存操作

44.4 Flash Performance And Reliability
44.4 闪存性能和可靠性

44.5 From Raw Flash to Flash-Based SSDs
44.5 从原始闪存到基于闪存的 SSD

44.6 FTL Organization: A Bad Approach
44.6 FTL 组织结构：一种糟糕的方法

44.7 A Log-Structured FTL
44.7 日志结构 FTL

44.8 Garbage Collection
44.8 垃圾回收

44.9 Mapping Table Size
44.9 映射表大小

44.10 Wear Leveling
44.10 磨损均衡

44.11 SSD Performance And Cost
44.11 SSD 性能和成本

44.12 Summary
44.12 总结

**45 Data Integrity and Protection**
45 数据完整性和保护

45.1 Disk Failure Modes
45.1 磁盘故障模式

45.2 Handling Latent Sector Errors
45.2 处理潜在扇区错误

45.3 Detecting Corruption: The Checksum
45.3 检测损坏：校验和

45.4 Using Checksums
45.4 使用校验和

45.5 A New Problem: Misdirected Writes
45.5 一个新问题：误导写入 (Misdirected Writes)

45.6 One Last Problem: Lost Writes
45.6 最后一个问题：丢失写入 (Lost Writes)

45.7 Scrubbing
45.7 清洗 (Scrubbing)

45.8 Overheads Of Checksumming
45.8 校验和的开销

45.9 Summary
45.9 总结

46 Summary Dialogue on Persistence
46 关于持久性的总结对话

47 A Dialogue on Distribution
47 关于分布式的对话

48 Distributed Systems
48 分布式系统

48.1 Communication Basics
48.1 通信基础

48.2 Unreliable Communication Layers
48.2 不可靠通信层

48.3 Reliable Communication Layers
48.3 可靠通信层

48.4 Communication Abstractions
48.4 通信抽象

48.5 Remote Procedure Call (RPC)
48.5 远程过程调用 (RPC)

48.6 Summary
48.6 总结

**49 Sun's Network File System (NFS)**
49 Sun 的网络文件系统 (NFS)

49.1 A Basic Distributed File System
49.1 一个基本的分布式文件系统

49.2 On To NFS
49.2 进入 NFS

49.3 Focus: Simple And Fast Server Crash Recovery
49.3 重点：简单快速的服务器崩溃恢复

49.4 Key To Fast Crash Recovery: Statelessness
49.4 快速崩溃恢复的关键：无状态性

49.5 The NFSv2 Protocol
49.5 NFSv2 协议

49.6 From Protocol To Distributed File System
49.6 从协议到分布式文件系统

49.7 Handling Server Failure With Idempotent Operations
49.7 使用幂等操作处理服务器故障

49.8 Improving Performance: Client-side Caching
49.8 提高性能：客户端缓存

49.9 The Cache Consistency Problem
49.9 缓存一致性问题

49.10 Assessing NFS Cache Consistency
49.10 评估 NFS 缓存一致性

49.11 Implications On Server-Side Write Buffering
49.11 对服务器端写入缓冲的影响

49.12 Summary
49.12 总结

**50 The Andrew File System (AFS)**
50 Andrew 文件系统 (AFS)

50.1 AFS Version 1
50.1 AFS 版本 1

50.2 Problems with Version 1
50.2 版本 1 的问题

50.3 Improving the Protocol
50.3 改进协议

50.4 AFS Version 2
50.4 AFS 版本 2

50.5 Cache Consistency
50.5 缓存一致性

50.6 Crash Recovery
50.6 崩溃恢复

50.7 Scale And Performance Of AFSv2
50.7 AFSv2 的规模和性能

50.8 AFS: Other Improvements
50.8 AFS：其他改进

50.9 Summary
50.9 总结

51 Summary Dialogue on Distribution
51 关于分布式的总结对话

General Index
总索引

Asides
旁白

Tips
提示

Cruces
关键问题

**1 A Dialogue on the Book**
1 关于本书的对话

Professor: Welcome to this book!
教授：欢迎阅读本书！

It's called **Operating Systems in Three Easy Pieces**, and I am here to teach you the things you need to know about operating systems.
它的名字叫《**操作系统导论**》（**Operating Systems in Three Easy Pieces**），我在这里是为了教你关于操作系统需要了解的知识。

I am called "Professor"; who are you?
我被称为“教授”；你是谁？

Student: Hi Professor!
学生：嗨，教授！

I am called "Student", as you might have guessed.
正如你可能猜到的那样，我被称为“学生”。

And I am here and ready to learn!
我已经准备好学习了！

Professor: Sounds good. Any questions?
教授：听起来不错。有什么问题吗？

Student: Sure! Why is it called "Three Easy Pieces"?
学生：当然！为什么叫“三个简单的部分”？

Professor: That's an easy one.
教授：这很容易回答。

Well, you see, there are these great lectures on Physics by Richard Feynman...
嗯，你看，理查德·费曼有一些关于物理学的精彩讲座……

Student: Oh! The guy who wrote "Surely You're Joking, Mr. Feynman", right?
学生：哦！就是写《别闹了，费曼先生》的那个人，对吧？

Great book!
很棒的书！

Is this going to be hilarious like that book was?
这本书会像那本书一样幽默吗？

Professor: Um... well, no.
教授：呃……好吧，不是。

That book was great, and I'm glad you've read it.
那本书很棒，我很高兴你读过。

Hopefully this book is more like his notes on Physics.
希望这本书更像他的物理学讲义。

Some of the basics were summed up in a book called "Six Easy Pieces".
一些基础知识被总结在一本名为《物理之美：费曼物理学讲义入门选》（Six Easy Pieces）的书中。

He was talking about Physics; we're going to do Three Easy Pieces on the fine topic of Operating Systems.
他谈论的是物理学；我们将针对操作系统这个精妙的主题进行“三个简单的部分”的讲解。

This is appropriate, as Operating Systems are about half as hard as Physics.
这很合适，因为操作系统的难度大约是物理学的一半。

Student: Well, I liked physics, so that is probably good.
学生：嗯，我喜欢物理，所以这大概是件好事。

What are those pieces?
那些部分是什么？

Professor: They are the three key ideas we're going to learn about: virtualization, concurrency, and persistence.
教授：它们是我们将要学习的三个关键思想：虚拟化、并发和持久性。

In learning about these ideas, we'll learn all about how an operating system works, including how it decides what program to run next on a CPU, how it handles memory overload in a virtual memory system, how virtual machine monitors work, how to manage information on disks, and even a little about how to build a distributed system that works when parts have failed.
在学习这些思想的过程中，我们将全面了解操作系统是如何工作的，包括它如何决定接下来在 CPU 上运行哪个程序，如何在虚拟内存系统中处理内存过载，虚拟机监视器如何工作，如何管理磁盘上的信息，甚至还会涉及一点关于如何构建在部分组件失效时仍能工作的分布式系统。

That sort of stuff.
诸如此类的事情。

Student: I have no idea what you're talking about, really.
学生：说实话，我完全不知道你在说什么。

Professor: Good! That means you are in the right class.
教授：很好！这意味着你来对课堂了。

Student: I have another question: what's the best way to learn this stuff?
学生：我还有一个问题：学习这些东西的最好方法是什么？

Professor: Excellent query!
教授：极好的问题！

Well, each person needs to figure this out on their own, of course, but here is what I would do: go to class, to hear the professor introduce the material.
当然，每个人都需要自己找到适合的方法，但我会这样做：去上课，听教授介绍材料。

Then, at the end of every week, read these notes, to help the ideas sink into your head a bit better.
然后，在每周结束时，阅读这些笔记，以帮助这些思想更好地深入你的脑海。

Of course, some time later (hint: before the exam!), read the notes again to firm up your knowledge.
当然，过段时间（提示：在考试前！），再次阅读笔记以巩固你的知识。

Of course, your professor will no doubt assign some homeworks and projects, so you should do those; in particular, doing projects where you write real code to solve real problems is the best way to put the ideas within these notes into action.
当然，你的教授毫无疑问会布置一些家庭作业和项目，所以你应该完成它们；特别是，做那些编写真实代码来解决实际问题的项目，是将这些笔记中的思想付诸实践的最佳方式。

As Confucius said...
正如孔子所说……

Student: Oh, I know!
学生：哦，我知道！

'I hear and I forget. I see and I remember. I do and I understand.'
“不闻不若闻之，闻之不若见之，见之不若知之，知之不若行之。”（此处原文引用英文俗语，对应中文典故为荀子《儒效》篇，非孔子）

Or something like that.
或者类似的说法。

Professor: (surprised) How did you know what I was going to say?!
教授：（惊讶）你怎么知道我要说什么？！

Student: It seemed to follow.
学生：这似乎是顺理成章的。

Also, I am a big fan of Confucius, and an even bigger fan of Xunzi, who actually is a better source for this quote.
而且，我是孔子的超级粉丝，更是荀子的超级粉丝，他实际上才是这句话更好的出处。

Professor: (stunned) Well, I think we are going to get along just fine!
教授：（惊呆了）好吧，我想我们会相处得很好！

Just fine indeed.
确实会很好。

Student: Professor - just one more question, if I may.
学生：教授——如果可以的话，还有一个问题。

What are these dialogues for?
这些对话是用来做什么的？

I mean, isn't this just supposed to be a book?
我的意思是，这不应该只是一本书吗？

Why not present the material directly?
为什么不直接展示材料呢？

Professor: Ah, good question, good question!
教授：啊，好问题，好问题！

Well, I think it is sometimes useful to pull yourself outside of a narrative and think a bit; these dialogues are those times.
嗯，我认为有时把自己从叙述中抽离出来思考一下是有用的；这些对话就是这样的时刻。

So you and I are going to work together to make sense of all of these pretty complex ideas.
所以你和我将一起努力理清所有这些相当复杂的思想。

Are you up for it?
你准备好了吗？

Student: So we have to think?
学生：所以我们必须思考？

Well, I'm up for that.
好吧，我准备好了。

I mean, what else do I have to do anyhow?
我的意思是，反正我还能做什么呢？

It's not like I have much of a life outside of this book.
我就像在这本书之外没什么生活一样。

Professor: Me neither, sadly.
教授：遗憾的是，我也一样。

So let's get to work!
所以让我们开始工作吧！

**2 Introduction to Operating Systems**
2 操作系统介绍

If you are taking an undergraduate operating systems course, you should already have some idea of what a computer program does when it runs.
如果你正在修读本科操作系统课程，你应该已经对计算机程序运行时做什么有了一些概念。

If not, this book (and the corresponding course) is going to be difficult so you should probably stop reading this book, or run to the nearest bookstore and quickly consume the necessary background material before continuing (both Patt & Patel and Bryant & O'Hallaron are pretty great books).
如果没有，这本书（以及相应的课程）将会很难，所以你可能应该停止阅读这本书，或者跑到最近的书店，快速消化必要的背景材料再继续（Patt & Patel 以及 Bryant & O'Hallaron 的书都很棒）。

So what happens when a program runs?
那么当程序运行时会发生什么呢？

Well, a running program does one very simple thing: it executes instructions.
嗯，一个正在运行的程序做一件非常简单的事情：它执行指令。

Many millions (and these days, even billions) of times every second, the processor fetches an instruction from memory, decodes it (i.e., figures out which instruction this is), and executes it (i.e., it does the thing that it is supposed to do, like add two numbers together, access memory, check a condition, jump to a function, and so forth).
每秒数百万次（现在甚至数十亿次），处理器从内存中取出一鸣指令，解码它（即弄清楚这是哪条指令），并执行它（即做它应该做的事情，比如将两个数字相加、访问内存、检查条件、跳转到函数等等）。

After it is done with this instruction, the processor moves on to the next instruction, and so on, and so on, until the program finally completes.
在完成这条指令后，处理器继续执行下一条指令，依此类推，直到程序最终完成。

Thus, we have just described the basics of the Von Neumann model of computing.
因此，我们要刚刚描述了冯·诺依曼计算模型的基础知识。

Sounds simple, right?
听起来很简单，对吧？

But in this class, we will be learning that while a program runs, a lot of other wild things are going on with the primary goal of making the system easy to use.
但是在这门课上，我们将了解到，当程序运行时，还会发生很多其他疯狂的事情，其主要目标是使系统易于使用。

There is a body of software, in fact, that is responsible for making it easy to run programs (even allowing you to seemingly run many at the same time), allowing programs to share memory, enabling programs to interact with devices, and other fun stuff like that.
事实上，有一套软件负责使运行程序变得容易（甚至允许你看起来同时运行许多程序），允许程序共享内存，使程序能够与设备交互，以及其他类似有趣的事情。

That body of software is called the **operating system** (OS), as it is in charge of making sure the system operates correctly and efficiently in an easy-to-use manner.
这套软件被称为**操作系统** (OS)，因为它负责确保系统以易于使用的方式正确高效地运行。

**The Crux of the Problem: How to Virtualize Resources**
**问题的关键：如何虚拟化资源**

One central question we will answer in this book is quite simple: how does the operating system virtualize resources?
我们将在本书中回答的一个核心问题非常简单：操作系统如何虚拟化资源？

This is the crux of our problem.
这是我们问题的关键。

Why the OS does this is not the main question, as the answer should be obvious: it makes the system easier to use.
操作系统为什么这样做不是主要问题，因为答案应该是显而易见的：它使系统更易于使用。

Thus, we focus on the **how**: what mechanisms and policies are implemented by the OS to attain virtualization?
因此，我们要关注**如何做**：操作系统实施了哪些机制和策略来实现虚拟化？

How does the OS do so efficiently?
操作系统如何高效地做到这一点？

What hardware support is needed?
需要什么硬件支持？

We will use the "crux of the problem", in shaded boxes such as this one, as a way to call out specific problems we are trying to solve in building an operating system.
我们将使用“问题的关键”（如本框所示的阴影框）来指出我们在构建操作系统时试图解决的具体问题。

Thus, within a note on a particular topic, you may find one or more cruces (yes, this is the proper plural) which highlight the problem.
因此，在关于特定主题的笔记中，你可能会发现一个或多个 cruces（是的，这是 crux 的正确复数形式），它们突出了问题。

The details within the chapter, of course, present the solution, or at least the basic parameters of a solution.
当然，章节中的细节会提供解决方案，或者至少是解决方案的基本参数。

The primary way the OS does this is through a general technique that we call **virtualization**.
操作系统执行此操作的主要方式是通过一种我们要称为**虚拟化**的通用技术。

That is, the OS takes a physical resource (such as the processor, or memory, or a disk) and transforms it into a more general, powerful, and easy-to-use virtual form of itself.
也就是说，操作系统获取物理资源（如处理器、内存或磁盘）并将其转换为更通用、更强大且更易于使用的虚拟形式。

Thus, we sometimes refer to the operating system as a **virtual machine**.
因此，我们要有时将操作系统称为**虚拟机**。

Of course, in order to allow users to tell the OS what to do and thus make use of the features of the virtual machine (such as running a program, or allocating memory, or accessing a file), the OS also provides some interfaces (APIs) that you can call.
当然，为了允许用户告诉操作系统要做什么，从而利用虚拟机的特性（如运行程序、分配内存或访问文件），操作系统还提供了一些你可以调用的接口 (API)。

A typical OS, in fact, exports a few hundred **system calls** that are available to applications.
事实上，典型的操作系统会向应用程序导出几百个**系统调用**。

Because the OS provides these calls to run programs, access memory and devices, and other related actions, we also sometimes say that the OS provides a **standard library** to applications.
因为操作系统提供这些调用来运行程序、访问内存和设备以及其他相关操作，我们要有时也说操作系统为应用程序提供了一个**标准库**。

Finally, because virtualization allows many programs to run (thus sharing the CPU), and many programs to concurrently access their own instructions and data (thus sharing memory), and many programs to access devices (thus sharing disks and so forth), the OS is sometimes known as a **resource manager**.
最后，因为虚拟化允许许多程序运行（从而共享 CPU），许多程序并发访问它们自己的指令和数据（从而共享内存），以及许多程序访问设备（从而共享磁盘等），操作系统有时被称为**资源管理器**。

Each of the CPU, memory, and disk is a **resource** of the system; it is thus the operating system's role to manage those resources, doing so efficiently or fairly or indeed with many other possible goals in mind.
CPU、内存和磁盘中的每一个都是系统的**资源**；因此，操作系统的角色是管理这些资源，以高效、公平或实际上许多其他可能的目标来做这件事。

To understand the role of the OS a little bit better, let's take a look at some examples.
为了更好地理解操作系统的角色，让我们看一些例子。

**2.1 Virtualizing The CPU**
2.1 CPU 虚拟化

Figure 2.1 depicts our first program.
图 2.1 描绘了我们的第一个程序。

It doesn't do much.
它没做什么事。

In fact, all it does is call `Spin()`, a function that repeatedly checks the time and returns once it has run for a second.
事实上，它所做的只是调用 `Spin()`，这是一个反复检查时间并在运行一秒钟后返回的函数。

Then, it prints out the string that the user passed in on the command line, and repeats, forever.
然后，它打印出用户在命令行上传入的字符串，并永远重复。

Let's say we save this file as `cpu.c` and decide to compile and run it on a system with a single processor (or CPU as we will sometimes call it).
假设我们将此文件保存为 `cpu.c`，并决定在具有单个处理器（或者我们有时称之为 CPU）的系统上编译并运行它。

Here is what we will see:
这是我们将看到的：

`prompt> gcc -o cpu cpu.c -Wall`
`prompt> ./cpu "A"`
A
A
A
A
^C
`prompt>`

Not too interesting of a run - the system begins running the program, which repeatedly checks the time until a second has elapsed.
运行起来不太有趣——系统开始运行程序，程序反复检查时间直到一秒钟过去。

Once a second has passed, the code prints the input string passed in by the user (in this example, the letter "A"), and continues.
一旦一秒钟过去，代码就会打印用户传入的输入字符串（在本例中为字母 "A"），然后继续。

Note the program will run forever; by pressing "Control-c" (which on UNIX-based systems will terminate the program running in the foreground) we can halt the program.
注意程序将永远运行；通过按 "Control-c"（在基于 UNIX 的系统上将终止在前台运行的程序），我们可以停止程序。

Now, let's do the same thing, but this time, let's run many different instances of this same program.
现在，让我们做同样的事情，但这次，我们要运行同一个程序的许多不同实例。

Figure 2.2 shows the results of this slightly more complicated example.
图 2.2 显示了这个稍微复杂一点的例子的结果。

`prompt> ./cpu A & ./cpu B & ./cpu C & ./cpu D &`
`[1] 7353`
`[2] 7354`
`[3] 7355`
`[4] 7356`
A
B
D
C
A
B
D
C
A
...

Well, now things are getting a little more interesting.
嗯，现在事情变得更有趣了一点。

Even though we have only one processor, somehow all four of these programs seem to be running at the same time!
即使我们只有一个处理器，但这四个程序似乎都在同时运行！

How does this magic happen?
这种魔法是如何发生的？

It turns out that the operating system, with some help from the hardware, is in charge of this illusion, i.e., the illusion that the system has a very large number of virtual CPUs.
原来是操作系统在硬件的帮助下负责这种错觉，即系统拥有大量虚拟 CPU 的错觉。

Turning a single CPU (or a small set of them) into a seemingly infinite number of CPUs and thus allowing many programs to seemingly run at once is what we call **virtualizing the CPU**, the focus of the first major part of this book.
将单个 CPU（或一小组 CPU）变成看似无限数量的 CPU，从而允许许多程序看似同时运行，这就是我们要称为**虚拟化 CPU** 的技术，这也是本书第一主要部分的重点。

Of course, to run programs, and stop them, and otherwise tell the OS which programs to run, there need to be some interfaces (APIs) that you can use to communicate your desires to the OS.
当然，为了运行程序、停止程序以及以其他方式告诉操作系统运行哪些程序，需要有一些接口 (API) 供你用来与操作系统交流你的意愿。

We'll talk about these APIs throughout this book; indeed, they are the major way in which most users interact with operating systems.
我们将在整本书中讨论这些 API；实际上，它们是大多数用户与操作系统交互的主要方式。

You might also notice that the ability to run multiple programs at once raises all sorts of new questions.
你可能还会注意到，同时运行多个程序的能力引发了各种新问题。

For example, if two programs want to run at a particular time, which should run?
例如，如果两个程序想在特定时间运行，应该运行哪一个？

This question is answered by a **policy** of the OS; policies are used in many different places within an OS to answer these types of questions, and thus we will study them as we learn about the basic mechanisms that operating systems implement (such as the ability to run multiple programs at once).
这个问题由操作系统的**策略**回答；策略在操作系统内的许多不同地方用于回答此类问题，因此我们将在学习操作系统实施的基本机制（如同时运行多个程序的能力）时研究它们。

Hence the role of the OS as a resource manager.
因此，这也是操作系统作为资源管理器的角色。

**2.2 Virtualizing Memory**
2.2 虚拟化内存

Now let's consider memory.
现在让我们考虑内存。

The model of physical memory presented by modern machines is very simple.
现代机器呈现的物理内存模型非常简单。

Memory is just an array of bytes; to read memory, one must specify an address to be able to access the data stored there; to write (or update) memory, one must also specify the data to be written to the given address.
内存只是一个字节数组；要读取内存，必须指定一个地址才能访问存储在那里的数据；要写入（或更新）内存，还必须指定要写入给定地址的数据。

Memory is accessed all the time when a program is running.
程序运行时一直都在访问内存。

A program keeps all of its data structures in memory, and accesses them through various instructions, like loads and stores or other explicit instructions that access memory in doing their work.
程序将其所有数据结构保存在内存中，并通过各种指令访问它们，例如加载和存储或其他在工作时访问内存的显式指令。

Don't forget that each instruction of the program is in memory too; thus memory is accessed on each instruction fetch.
别忘了程序的每一条指令也在内存中；因此，每次获取指令时都会访问内存。

Let's take a look at a program (in Figure 2.3) that allocates some memory by calling `malloc()`.
让我们看一个程序（在图 2.3 中），它通过调用 `malloc()` 分配一些内存。

The output of this program can be found here:
该程序的输出如下：

`prompt> ./mem`
`(2134) address pointed to by p: 0x200000`
`(2134) p: 1`
`(2134) p: 2`
`(2134) p: 3`
`(2134) p: 4`
`(2134) p: 5`
^C

The program does a couple of things.
程序做了几件事。

First, it allocates some memory (line a1).
首先，它分配一些内存（a1 行）。

Then, it prints out the address of the memory (a2), and then puts the number zero into the first slot of the newly allocated memory (a3).
然后，它打印出内存的地址 (a2)，并将数字零放入新分配内存的第一个槽中 (a3)。

Finally, it loops, delaying for a second and incrementing the value stored at the address held in p.
最后，它循环，延迟一秒钟并增加存储在 p 中保存的地址处的值。

With every print statement, it also prints out what is called the process identifier (the PID) of the running program.
对于每个打印语句，它还会打印出正在运行的程序的进程标识符 (PID)。

This PID is unique per running process.
每个运行进程的 PID 都是唯一的。

Again, this first result is not too interesting.
同样，这第一个结果并不是太有趣。

The newly allocated memory is at address 0x200000.
新分配的内存位于地址 0x200000。

As the program runs, it slowly updates the value and prints out the result.
随着程序的运行，它会缓慢更新该值并打印出结果。

Now, we again run multiple instances of this same program to see what happens (Figure 2.4).
现在，我们要再次运行同一个程序的多个实例来看看会发生什么（图 2.4）。

`prompt> ./mem & ./mem &`
`[1] 24113`
`[2] 24114`
`(24113) address pointed to by p: 0x200000`
`(24114) address pointed to by p: 0x200000`
`(24113) p: 1`
`(24114) p: 1`
`(24114) p: 2`
`(24113) p: 2`
...

We see from the example that each running program has allocated memory at the same address (0x200000), and yet each seems to be updating the value at 0x200000 independently!
我们要从示例中看到，每个运行的程序都在相同的地址 (0x200000) 分配了内存，但每个程序似乎都在独立地更新 0x200000 处的值！

It is as if each running program has its own private memory, instead of sharing the same physical memory with other running programs.
这就好像每个运行的程序都有自己的私有内存，而不是与其他运行的程序共享相同的物理内存。

Indeed, that is exactly what is happening here as the OS is **virtualizing memory**.
事实上，这正是这里发生的事情，因为操作系统正在**虚拟化内存**。

Each process accesses its own private **virtual address space** (sometimes just called its **address space**), which the OS somehow maps onto the physical memory of the machine.
每个进程访问其自己的私有**虚拟地址空间**（有时简称为**地址空间**），操作系统以某种方式将其映射到机器的物理内存上。

A memory reference within one running program does not affect the address space of other processes (or the OS itself); as far as the running program is concerned, it has physical memory all to itself.
一个正在运行的程序中的内存引用不会影响其他进程（或操作系统本身）的地址空间；就正在运行的程序而言，它完全拥有物理内存。

The reality, however, is that physical memory is a shared resource, managed by the operating system.
然而，现实情况是物理内存是由操作系统管理的共享资源。

Exactly how all of this is accomplished is also the subject of the first part of this book, on the topic of virtualization.
所有这一切究竟是如何完成的也是本书第一部分的主题，即关于虚拟化的主题。

**2.3 Concurrency**
2.3 并发

Another main theme of this book is **concurrency**.
本书的另一个主要主题是**并发**。

We use this conceptual term to refer to a host of problems that arise, and must be addressed, when working on many things at once (i.e., concurrently) in the same program.
我们要使用这个概念性术语来指代在同一个程序中同时（即并发）处理许多事情时出现且必须解决的一系列问题。

The problems of concurrency arose first within the operating system itself; as you can see in the examples above on virtualization, the OS is juggling many things at once, first running one process, then another, and so forth.
并发问题首先出现在操作系统本身内部；正如你在上面关于虚拟化的示例中看到的那样，操作系统同时处理许多事情，先运行一个进程，然后运行另一个进程，依此类推。

As it turns out, doing so leads to some deep and interesting problems.
事实证明，这样做会导致一些深刻而有趣的问题。

Unfortunately, the problems of concurrency are no longer limited just to the OS itself.
不幸的是，并发问题不再仅限于操作系统本身。

Indeed, modern multi-threaded programs exhibit the same problems.
事实上，现代多线程程序也表现出同样的问题。

Let us demonstrate with an example of a multi-threaded program (Figure 2.5).
让我们用一个多线程程序的例子来演示（图 2.5）。

Although you might not understand this example fully at the moment (and we'll learn a lot more about it in later chapters, in the section of the book on concurrency), the basic idea is simple.
虽然你现在可能不完全理解这个例子（我们要将在后面的章节中，在本书关于并发的部分学到更多），但基本思想很简单。

The main program creates two **threads** using `Pthread_create()`.
主程序使用 `Pthread_create()` 创建两个**线程**。

You can think of a thread as a function running within the same memory space as other functions, with more than one of them active at a time.
你可以将线程视为在与其他函数相同的内存空间中运行的函数，并且一次有多个线程处于活动状态。

In this example, each thread starts running in a routine called `worker()`, in which it simply increments a counter in a loop for `loops` number of times.
在此示例中，每个线程都开始在一个名为 `worker()` 的例程中运行，在该例程中，它只是在一个循环中将计数器递增 `loops` 次。

Below is a transcript of what happens when we run this program with the input value for the variable `loops` set to 1000.
下面是当我们将变量 `loops` 的输入值设置为 1000 时运行此程序发生的情况的记录。

The value of `loops` determines how many times each of the two workers will increment the shared counter in a loop.
`loops` 的值决定了两个工作线程各自将在循环中递增共享计数器多少次。

When the program is run with the value of `loops` set to 1000, what do you expect the final value of counter to be?
当程序在 `loops` 值设置为 1000 的情况下运行时，你预计计数器的最终值是多少？

`prompt> gcc -o threads threads.c -Wall -pthread`
`prompt> ./threads 1000`
`Initial value: 0`
`Final value : 2000`

As you probably guessed, when the two threads are finished, the final value of the counter is 2000, as each thread incremented the counter 1000 times.
正如你可能猜到的那样，当两个线程完成时，计数器的最终值为 2000，因为每个线程都将计数器递增了 1000 次。

Indeed, when the input value of `loops` is set to N, we would expect the final output of the program to be 2N.
实际上，当 `loops` 的输入值设置为 N 时，我们要期望程序的最终输出为 2N。

But life is not so simple, as it turns out.
但事实证明，生活并非如此简单。

Let's run the same program, but with higher values for `loops`, and see what happens:
让我们运行相同的程序，但使用更大的 `loops` 值，看看会发生什么：

`prompt> ./threads 100000`
`Initial value: 0`
`Final value : 143012`
`prompt> ./threads 100000`
`Initial value: 0`
`Final value : 137298`
// huh??
// what the??

In this run, when we gave an input value of 100,000, instead of getting a final value of 200,000, we instead first get 143,012.
在这次运行中，当我们给出 100,000 的输入值时，我要没有得到 200,000 的最终值，而是首先得到了 143,012。

Then, when we run the program a second time, we not only again get the wrong value, but also a different value than the last time.
然后，当我们第二次运行该程序时，我们不仅再次得到了错误的值，而且还得到了与上次不同的值。

In fact, if you run the program over and over with high values of `loops`, you may find that sometimes you even get the right answer!
事实上，如果你用很大的 `loops` 值反复运行该程序，你可能会发现有时你甚至会得到正确的答案！

So why is this happening?
那么为什么会发生这种情况呢？

As it turns out, the reason for these odd and unusual outcomes relate to how instructions are executed, which is one at a time.
事实证明，这些奇怪而不寻常的结果的原因与指令的执行方式有关，即一次执行一条指令。

Unfortunately, a key part of the program above, where the shared counter is incremented, takes three instructions: one to load the value of the counter from memory into a register, one to increment it, and one to store it back into memory.
不幸的是，上面程序的关键部分（共享计数器递增的地方）需要三条指令：一条将计数器的值从内存加载到寄存器中，一条将其递增，另一条将其存回内存。

Because these three instructions do not execute **atomically** (all at once), strange things can happen.
因为这三条指令不是**原子地**（一次性全部）执行的，所以可能会发生奇怪的事情。

**The Crux of the Problem: How to Build Correct Concurrent Programs**
**问题的关键：如何构建正确的并发程序**

When there are many concurrently executing threads within the same memory space, how can we build a correctly working program?
当同一内存空间内有许多并发执行的线程时，我们如何构建一个正确工作的程序？

What primitives are needed from the OS?
需要操作系统提供什么原语？

What mechanisms should be provided by the hardware?
硬件应该提供什么机制？

How can we use them to solve the problems of concurrency?
我们如何使用它们来解决并发问题？

It is this problem of concurrency that we will address in great detail in the second part of this book.
我们将在本书的第二部分详细讨论这个并发问题。

**2.4 Persistence**
2.4 持久性

The third major theme of the course is **persistence**.
本课程的第三个主要主题是**持久性**。

In system memory, data can be easily lost, as devices such as DRAM store values in a volatile manner; when power goes away or the system crashes, any data in memory is lost.
在系统内存中，数据很容易丢失，因为像 DRAM 这样的设备以易失的方式存储值；当断电或系统崩溃时，内存中的任何数据都会丢失。

Thus, we need hardware and software to be able to store data **persistently**; such storage is thus critical to any system as users care a great deal about their data.
因此，我们需要硬件和软件能够**持久地**存储数据；这种存储因此对任何系统都至关重要，因为用户非常关心他们的数据。

The hardware comes in the form of some kind of input/output or I/O device; in modern systems, a hard drive is a common repository for long-lived information, although solid-state drives (SSDs) are making headway in this arena as well.
硬件以某种输入/输出或 I/O 设备的形式出现；在现代系统中，硬盘驱动器是长期信息的常见存储库，尽管固态驱动器 (SSD) 也在该领域取得进展。

The software in the operating system that usually manages the disk is called the **file system**; it is thus responsible for storing any files the user creates in a reliable and efficient manner on the disks of the system.
通常管理磁盘的操作系统软件称为**文件系统**；因此，它负责以可靠和高效的方式将用户创建的任何文件存储在系统的磁盘上。

Unlike the abstractions provided by the OS for the CPU and memory, the OS does not create a private, virtualized disk for each application.
与操作系统为 CPU 和内存提供的抽象不同，操作系统不会为每个应用程序创建一个私有的虚拟化磁盘。

Rather, it is assumed that often times, users will want to share information that is in files.
相反，人们假设用户通常希望共享文件中的信息。

For example, when writing a C program, you might first use an editor (e.g., Emacs) to create and edit the C file (`emacs -nw main.c`).
例如，在编写 C 程序时，你可能首先使用编辑器（如 Emacs）创建和编辑 C 文件 (`emacs -nw main.c`)。

Once done, you might use the compiler to turn the source code into an executable (e.g., `gcc -o main main.c`).
完成后，你可能会使用编译器将源代码转换为可执行文件（例如 `gcc -o main main.c`）。

When you're finished, you might run the new executable (e.g., `./main`).
完成后，你可能会运行新的可执行文件（例如 `./main`）。

Thus, you can see how files are shared across different processes.
因此，你可以看到文件是如何在不同进程之间共享的。

First, Emacs creates a file that serves as input to the compiler; the compiler uses that input file to create a new executable file (in many steps - take a compiler course for details); finally, the new executable is then run.
首先，Emacs 创建一个文件作为编译器的输入；编译器使用该输入文件创建一个新的可执行文件（分许多步骤——详情请参加编译器课程）；最后，运行新的可执行文件。

And thus a new program is born!
就这样，一个新程序诞生了！

To understand this better, let's look at some code.
为了更好地理解这一点，让我们看一些代码。

Figure 2.6 presents code to create a file (`/tmp/file`) that contains the string "hello world".
图 2.6 展示了创建一个包含字符串 "hello world" 的文件 (`/tmp/file`) 的代码。

To accomplish this task, the program makes three calls into the operating system.
为了完成此任务，程序向操作系统发出了三个调用。

The first, a call to `open()`, opens the file and creates it; the second, `write()`, writes some data to the file; the third, `close()`, simply closes the file thus indicating the program won't be writing any more data to it.
第一个调用 `open()` 打开并创建文件；第二个调用 `write()` 将一些数据写入文件；第三个调用 `close()` 只是关闭文件，从而表明程序不会再向其写入任何数据。

These system calls are routed to the part of the operating system called the file system, which then handles the requests and returns some kind of error code to the user.
这些系统调用被路由到操作系统中称为文件系统的部分，然后由文件系统处理请求并将某种错误代码返回给用户。

You might be wondering what the OS does in order to actually write to disk.
你可能想知道操作系统为了实际写入磁盘做了什么。

We would show you but you'd have to promise to close your eyes first; it is that unpleasant.
我们会给你看，但你得先保证闭上眼睛；那场面很不愉快。

The file system has to do a fair bit of work: first figuring out where on disk this new data will reside, and then keeping track of it in various structures the file system maintains.
文件系统必须做相当多的工作：首先弄清楚这个新数据将驻留在磁盘上的什么位置，然后在文件系统维护的各种结构中跟踪它。

Doing so requires issuing I/O requests to the underlying storage device, to either read existing structures or update (write) them.
这样做需要向底层存储设备发出 I/O 请求，以读取现有结构或更新（写入）它们。

As anyone who has written a device driver knows, getting a device to do something on your behalf is an intricate and detailed process.
任何写过设备驱动程序的人都知道，让设备代表你做某事是一个复杂而详细的过程。

It requires a deep knowledge of the low-level device interface and its exact semantics.
它需要对低级设备接口及其确切语义有深入的了解。

Fortunately, the OS provides a standard and simple way to access devices through its system calls.
幸运的是，操作系统提供了一种通过其系统调用访问设备的标准且简单的方法。

Thus, the OS is sometimes seen as a standard library.
因此，操作系统有时被视为标准库。

Of course, there are many more details in how devices are accessed, and how file systems manage data persistently atop said devices.
当然，关于如何访问设备以及文件系统如何在所述设备之上持久地管理数据，还有更多细节。

For performance reasons, most file systems first delay such writes for a while, hoping to batch them into larger groups.
出于性能原因，大多数文件系统首先将此类写入延迟一段时间，希望能将它们分批处理成更大的组。

To handle the problems of system crashes during writes, most file systems incorporate some kind of intricate write protocol, such as **journaling** or **copy-on-write**, carefully ordering writes to disk to ensure that if a failure occurs during the write sequence, the system can recover to reasonable state afterwards.
为了处理写入期间系统崩溃的问题，大多数文件系统都采用了某种复杂的写入协议，例如**日志记录**或**写时复制**，仔细排序对磁盘的写入，以确如果在写入序列期间发生故障，系统之后可以恢复到合理的状态。

**The Crux of the Problem: How to Store Data Persistently**
**问题的关键：如何持久地存储数据**

The file system is the part of the OS in charge of managing persistent data.
文件系统是操作系统中负责管理持久数据的部分。

What techniques are needed to do so correctly?
需要什么技术才能正确地做到这一点？

What mechanisms and policies are required to do so with high performance?
需要什么机制和策略才能以高性能做到这一点？

How is reliability achieved, in the face of failures in hardware and software?
面对硬件和软件故障，如何实现可靠性？

To make different common operations efficient, file systems employ many different data structures and access methods, from simple lists to complex b-trees.
为了使不同的常见操作高效，文件系统采用了许多不同的数据结构和访问方法，从简单的列表到复杂的 B 树。

If all of this doesn't make sense yet, good!
如果所有这些还没有意义，很好！

We'll be talking about all of this quite a bit more in the third part of this book on persistence, where we'll discuss devices and I/O in general, and then disks, RAIDs, and file systems in great detail.
我们要将在本书关于持久性的第三部分更多地讨论所有这些，我们将讨论一般的设备和 I/O，然后详细讨论磁盘、RAID 和文件系统。

**2.5 Design Goals**
2.5 设计目标

So now you have some idea of what an OS actually does: it takes physical resources, such as a CPU, memory, or disk, and virtualizes them.
现在你已经对操作系统实际做什么有了一些概念：它获取物理资源，如 CPU、内存或磁盘，并将它们虚拟化。

It handles tough and tricky issues related to concurrency.
它处理与并发相关的棘手问题。

And it stores files persistently, thus making them safe over the long-term.
它持久地存储文件，从而使它们在长期内安全。

Given that we want to build such a system, we want to have some goals in mind to help focus our design and implementation and make trade-offs as necessary; finding the right set of trade-offs is a key to building systems.
鉴于我们想要构建这样一个系统，我们希望心中有一些目标，以帮助我们专注于设计和实现，并在必要时进行权衡；找到正确的权衡组合是构建系统的关键。

One of the most basic goals is to build up some **abstractions** in order to make the system convenient and easy to use.
最基本的目标之一是建立一些**抽象**，以使系统方便易用。

Abstractions are fundamental to everything we do in computer science.
抽象是我们计算机科学中所做一切的基础。

Abstraction makes it possible to write a large program by dividing it into small and understandable pieces, to write such a program in a high-level language like C without thinking about assembly, to write code in assembly without thinking about logic gates, and to build a processor out of gates without thinking too much about transistors.
抽象使得编写大型程序成为可能，方法是将其划分为易于理解的小块；使得用 C 等高级语言编写此类程序成为可能，而无需考虑汇编；使得用汇编编写代码成为可能，而无需考虑逻辑门；使得用门构建处理器成为可能，而无需过多考虑晶体管。

Abstraction is so fundamental that sometimes we forget its importance, but we won't here; thus, in each section, we'll discuss some of the major abstractions that have developed over time, giving you a way to think about pieces of the OS.
抽象是如此基础，以至于有时我们会忘记它的重要性，但在这里我们不会忘记；因此，在每一节中，我们要讨论一些随着时间推移而发展起来的主要抽象，为你提供思考操作系统各个部分的方法。

One goal in designing and implementing an operating system is to provide **high performance**; another way to say this is our goal is to **minimize the overheads** of the OS.
设计和实现操作系统的一个目标是提供**高性能**；换句话说，我们的目标是**最小化操作系统的开销**。

Virtualization and making the system easy to use are well worth it, but not at any cost; thus, we must strive to provide virtualization and other OS features without excessive overheads.
虚拟化和使系统易于使用是非常值得的，但不是不计代价的；因此，我们要努力提供虚拟化和其他操作系统特性，而不会产生过多的开销。

These overheads arise in a number of forms: extra time (more instructions) and extra space (in memory or on disk).
这些开销以多种形式出现：额外的时间（更多的指令）和额外的空间（在内存或磁盘上）。

We'll seek solutions that minimize one or the other or both, if possible.
如果在可能的情况下，我们要寻求最小化其中之一或两者的解决方案。

Perfection, however, is not always attainable, something we will learn to notice and (where appropriate) tolerate.
然而，完美并非总能达到，我们要将学会注意到这一点，并在适当的时候容忍它。

Another goal will be to provide **protection** between applications, as well as between the OS and applications.
另一个目标是在应用程序之间以及操作系统和应用程序之间提供**保护**。

Because we wish to allow many programs to run at the same time, we want to make sure that the malicious or accidental bad behavior of one does not harm others; we certainly don't want an application to be able to harm the OS itself (as that would affect all programs running on the system).
因为我们希望允许许多程序同时运行，所以我们要确保一个程序的恶意或意外不良行为不会伤害其他程序；我们当然不希望应用程序能够伤害操作系统本身（因为那会影响系统上运行的所有程序）。

Protection is at the heart of one of the main principles underlying an operating system, which is that of **isolation**; isolating processes from one another is the key to protection and thus underlies much of what an OS must do.
保护是操作系统主要原则之一的核心，即**隔离**；将进程彼此隔离是保护的关键，因此也是操作系统必须做的大部分工作的基础。

The operating system must also run non-stop; when it fails, all applications running on the system fail as well.
操作系统还必须不间断地运行；当它出现故障时，系统上运行的所有应用程序也会失败。

Because of this dependence, operating systems often strive to provide a high degree of **reliability**.
由于这种依赖性，操作系统通常努力提供高度的**可靠性**。

As operating systems grow evermore complex (sometimes containing millions of lines of code), building a reliable operating system is quite a challenge - and indeed, much of the on-going research in the field (including some of our own work) focuses on this exact problem.
随着操作系统变得越来越复杂（有时包含数百万行代码），构建可靠的操作系统是一项相当大的挑战——事实上，该领域正在进行的许多研究（包括我们要自己的一些工作）都集中在这个确切的问题上。

Other goals make sense: **energy-efficiency** is important in our increasingly green world; **security** (an extension of protection, really) against malicious applications is critical, especially in these highly-networked times; **mobility** is increasingly important as OSes are run on smaller and smaller devices.
其他目标也是有意义的：在我们日益绿色的世界中，**能源效率**很重要；针对恶意应用程序的**安全性**（实际上是保护的延伸）至关重要，特别是在这个高度网络化的时代；随着操作系统在越来越小的设备上运行，**移动性**越来越重要。

Depending on how the system is used, the OS will have different goals and thus likely be implemented in at least slightly different ways.
根据系统的使用方式，操作系统将有不同的目标，因此可能会以至少略有不同的方式实现。

However, as we will see, many of the principles we will present on how to build an OS are useful on a range of different devices.
然而，正如我们将看到的，我们将介绍的关于如何构建操作系统的许多原则在一系列不同的设备上都是有用的。

**2.6 Some History**
2.6 一些历史

Before closing this introduction, let us present a brief history of how operating systems developed.
在结束本介绍之前，让我们简要介绍一下操作系统是如何发展的。

Like any system built by humans, good ideas accumulated in operating systems over time, as engineers learned what was important in their design.
像任何人类构建的系统一样，随着工程师们了解到设计中什么是重要的，好点子在操作系统中随时间积累。

Here, we discuss a few major developments.
在这里，我们要讨论几个主要的发展。

For a richer treatment, see Brinch Hansen's excellent history of operating systems.
要获得更丰富的内容，请参阅 Brinch Hansen 优秀的操作系统历史。

**Early Operating Systems: Just Libraries**
**早期操作系统：仅仅是库**

In the beginning, the operating system didn't do too much.
一开始，操作系统并没有做太多事情。

Basically, it was just a set of libraries of commonly-used functions; for example, instead of having each programmer of the system write low-level I/O handling code, the "OS" would provide such APIs, and thus make life easier for the developer.
基本上，它只是一组常用函数的库；例如，与其让系统的每个程序员编写低级 I/O 处理代码，“操作系统”会提供此类 API，从而使开发人员的生活更轻松。

Usually, on these old mainframe systems, one program ran at a time, as controlled by a human operator.
通常，在这些旧的大型机系统上，一次运行一个程序，由人工操作员控制。

Much of what you think a modern OS would do (e.g., deciding what order to run jobs in) was performed by this operator.
你认为现代操作系统会做的大部分工作（例如，决定以什么顺序运行作业）都是由这位操作员完成的。

If you were a smart developer, you would be nice to this operator, so that they might move your job to the front of the queue.
如果你是一个聪明的开发人员，你会对这位操作员很好，这样他们可能会把你的作业移到队列的前面。

This mode of computing was known as **batch** processing, as a number of jobs were set up and then run in a "batch" by the operator.
这种计算模式被称为**批处理**，因为许多作业被设置好，然后由操作员“批量”运行。

Computers, as of that point, were not used in an interactive manner, because of cost: it was simply too expensive to let a user sit in front of the computer and use it, as most of the time it would just sit idle then, costing the facility hundreds of thousands of dollars per hour.
在那时，计算机并不是以交互方式使用的，因为成本太高：让用户坐在计算机前使用它实在是太贵了，因为大多数时候它只是闲置着，每小时花费设施数十万美元。

**Beyond Libraries: Protection**
**超越库：保护**

In moving beyond being a simple library of commonly-used services, operating systems took on a more central role in managing machines.
在超越常用服务的简单库的过程中，操作系统在管理机器方面承担了更核心的角色。

One important aspect of this was the realization that code run on behalf of the OS was special; it had control of devices and thus should be treated differently than normal application code.
其中一个重要方面是意识到代表操作系统运行的代码是特殊的；它控制着设备，因此应该与普通应用程序代码区别对待。

Why is this?
为什么会这样？

Well, imagine if you allowed any application to read from anywhere on the disk; the notion of privacy goes out the window, as any program could read any file.
嗯，想象一下，如果你允许任何应用程序从磁盘上的任何位置读取；隐私的概念就会消失，因为任何程序都可以读取任何文件。

Thus, implementing a file system (to manage your files) as a library makes little sense.
因此，将文件系统（管理你的文件）作为库来实现是没有意义的。

Instead, something else was needed.
相反，需要其他东西。

Thus, the idea of a **system call** was invented, pioneered by the Atlas computing system.
因此，**系统调用**的想法被发明出来，由 Atlas 计算系统首创。

Instead of providing OS routines as a library (where you just make a procedure call to access them), the idea here was to add a special pair of hardware instructions and hardware state to make the transition into the OS a more formal, controlled process.
与其将操作系统例程作为库提供（只需进行过程调用即可访问它们），这里的想法是添加一对特殊的硬件指令和硬件状态，使进入操作系统的转换成为一个更正式、受控的过程。

The key difference between a system call and a procedure call is that a system call transfers control (i.e., jumps) into the OS while simultaneously raising the hardware privilege level.
系统调用和过程调用之间的关键区别在于，系统调用将控制权转移（即跳转）到操作系统，同时提高硬件特权级别。

User applications run in what is referred to as **user mode** which means the hardware restricts what applications can do; for example, an application running in user mode can't typically initiate an I/O request to the disk, access any physical memory page, or send a packet on the network.
用户应用程序在所谓的**用户模式**下运行，这意味着硬件限制了应用程序可以做什么；例如，在用户模式下运行的应用程序通常无法向磁盘发起 I/O 请求、访问任何物理内存页面或在网络上发送数据包。

When a system call is initiated (usually through a special hardware instruction called a **trap**), the hardware transfers control to a pre-specified **trap handler** (that the OS set up previously) and simultaneously raises the privilege level to **kernel mode**.
当发起系统调用时（通常通过称为**陷阱**的特殊硬件指令），硬件将控制权转移到预先指定的**陷阱处理程序**（操作系统之前设置的），同时将特权级别提高到**内核模式**。

In kernel mode, the OS has full access to the hardware of the system and thus can do things like initiate an I/O request or make more memory available to a program.
在内核模式下，操作系统可以完全访问系统的硬件，因此可以做诸如发起 I/O 请求或为程序提供更多内存之类的事情。

When the OS is done servicing the request, it passes control back to the user via a special **return-from-trap** instruction, which reverts to user mode while simultaneously passing control back to where the application left off.
当操作系统完成服务请求时，它通过特殊的**从陷阱返回**指令将控制权交还给用户，该指令恢复到用户模式，同时将控制权交还给应用程序中断的地方。

**The Era of Multiprogramming**
**多道程序设计时代**

Where operating systems really took off was in the era of computing beyond the mainframe, that of the **minicomputer**.
操作系统真正腾飞是在超越大型机的计算时代，即**小型机**时代。

Classic machines like the PDP family from Digital Equipment made computers hugely more affordable; thus, instead of having one mainframe per large organization, now a smaller collection of people within an organization could likely have their own computer.
像 Digital Equipment 的 PDP 系列这样的经典机器使计算机更加实惠；因此，与其每个大型组织拥有一台大型机，现在组织内的一小群人可能拥有自己的计算机。

Not surprisingly, one of the major impacts of this drop in cost was an increase in developer activity; more smart people got their hands on computers and thus made computer systems do more interesting and beautiful things.
毫不奇怪，成本下降的主要影响之一是开发人员活动的增加；更多的聪明人接触到了计算机，从而使计算机系统做了更多有趣和美妙的事情。

In particular, **multiprogramming** became commonplace due to the desire to make better use of machine resources.
特别是，由于希望更好地利用机器资源，**多道程序设计**变得普遍起来。

Instead of just running one job at a time, the OS would load a number of jobs into memory and switch rapidly between them, thus improving CPU utilization.
与其一次只运行一个作业，操作系统会将许多作业加载到内存中并在它们之间快速切换，从而提高 CPU 利用率。

This switching was particularly important because I/O devices were slow; having a program wait on the CPU while its I/O was being serviced was a waste of CPU time.
这种切换特别重要，因为 I/O 设备很慢；让程序在等待 I/O 服务时占用 CPU 是对 CPU 时间的浪费。

Instead, why not switch to another job and run it for a while?
相反，为什么不切换到另一个作业并运行一段时间呢？

The desire to support multiprogramming and overlap in the presence of I/O and interrupts forced innovation in the conceptual development of operating systems along a number of directions.
支持多道程序设计以及在 I/O 和中断存在的情况下进行重叠的愿望迫使操作系统在概念发展方面沿着多个方向进行创新。

Issues such as memory protection became important; we wouldn't want one program to be able to access the memory of another program.
诸如内存保护之类的问题变得重要起来；我们要不希望一个程序能够访问另一个程序的内存。

Understanding how to deal with the concurrency issues introduced by multiprogramming was also critical; making sure the OS was behaving correctly despite the presence of interrupts is a great challenge.
理解如何处理由多道程序设计引入的并发问题也至关重要；确保操作系统在存在中断的情况下仍能正确运行是一项巨大的挑战。

We will study these issues and related topics later in the book.
我们将在本书后面研究这些问题和相关主题。

One of the major practical advances of the time was the introduction of the **UNIX** operating system, primarily thanks to Ken Thompson (and Dennis Ritchie) at Bell Labs (yes, the phone company).
当时主要的实践进步之一是 **UNIX** 操作系统的引入，这主要归功于贝尔实验室（是的，电话公司）的 Ken Thompson（和 Dennis Ritchie）。

UNIX took many good ideas from different operating systems (particularly from Multics, and some from systems like TENEX and the Berkeley Time-Sharing System), but made them simpler and easier to use.
UNIX 从不同的操作系统（特别是 Multics，以及 TENEX 和伯克利分时系统等系统）中吸取了许多好点子，但使它们更简单、更易于使用。

Soon this team was shipping tapes containing UNIX source code to people around the world, many of whom then got involved and added to the system themselves; see the Aside (next page) for more detail.
很快，这个团队就开始向世界各地的人们运送包含 UNIX 源代码的磁带，其中许多人随后参与进来并亲自为系统添砖加瓦；有关更多详细信息，请参阅旁白（下一页）。

**The Modern Era**
**现代**

Beyond the minicomputer came a new type of machine, cheaper, faster, and for the masses: the **personal computer**, or **PC** as we call it today.
继小型机之后，出现了一种新型机器，更便宜、更快、面向大众：**个人计算机**，也就是我们要今天所说的 **PC**。

Led by Apple's early machines (e.g., the Apple II) and the IBM PC, this new breed of machine would soon become the dominant force in computing.
在苹果早期机器（例如 Apple II）和 IBM PC 的带领下，这种新型机器很快将成为计算领域的主导力量。