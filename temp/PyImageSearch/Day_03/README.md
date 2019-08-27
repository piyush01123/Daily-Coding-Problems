Let me guess.

If you’ve taken other programming courses, the first app you built was probably kind of useless. You built it in order to learn some key elements of syntax or to understand certain programming concepts — loops, conditional statements, and classes, anyone? —  and maybe it even had a bit of a cool factor to it. But it wasn’t something you were going to actually use.

Well, the app you’re going to build today is one that is definitely useful: a computer vision-powered document scanner.

Image

Yep, one of my favorite things about OpenCV is that you can dive right in with projects that have real-world applications. And once you get started, you’ll quickly see how many ways computer vision can be truly useful in all kinds of projects.

Sure, "Hello, World" wowed us all once upon a time. But let’s go for something you could potentially use, shall we?

Building a document scanner in OpenCV boils down to three simple steps — and it’s going to take you just a few minutes.

All you have to do is:
Detect edges.
Use the edges in the image to find the contour (outline) representing the piece of paper being scanned.
Apply a perspective transform to obtain the top-down view of the document.
Do you have 20 minutes right now? Then let’s do this.
