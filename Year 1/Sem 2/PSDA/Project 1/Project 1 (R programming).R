Ques13.freq<-table(Ques13)
x_labels <- c("Strongly Disagree", "Disagree", "Neutral", "Agree", "Strongly Agree")
bar_colors <- c("red", "green", "blue", "orange", "purple")
barplot(Ques13.freq,
        col=bar_colors,
        ylab = "Frequency",
        xlab = "",
        names.arg = x_labels,
        ylim = c(0, 30),
        main = "Do you believe that participating in extracurricular activities or clubs will positively influence your studies?"
        )
text(x = barplot(Ques13.freq, plot = FALSE), y = Ques13.freq, labels = Ques13.freq, pos = 3, col = "black")
legend("topright", legend = x_labels, fill = bar_colors, cex = 0.6)

Ques14.freq <- table(Ques14)
x_labels <- c("Strongly Disagree", "Disagree", "Neutral", "Agree", "Strongly Agree")
bar_colors <- c("red", "green", "blue", "orange", "purple")
barplot(Ques14.freq,
        col=bar_colors,
        ylab = "Frequency",
        xlab = "",
        names.arg = x_labels,
        ylim = c(0, 50),
        main = "Do you agree that past year questions / papers can help a lot in preparations for the exams?"
)
text(x = barplot(Ques14.freq, plot = FALSE), y = Ques14.freq, labels = Ques14.freq, pos = 3, col = "black")
legend("topleft", legend = x_labels, fill = bar_colors, cex = 0.6)


Ques15.freq <- table(Ques15)
pie(Ques15.freq,
   main = "Time of practicing on past year question",
   labels = paste(names(Ques15.freq), "\n", Ques15.freq)
    )


Ques16.freq <- table(Ques16)
pie(Ques16.freq,
    main = "Result of student in Final Exam",
    labels = paste(names(Ques16.freq), "\n", Ques16.freq)
    )
library(plotrix)
pie3D(Ques16.freq,labels=names(Ques16.freq),main="Student CGPA",explode=0.1)


Ques17.freq <- table(Ques17)
x_labels <- c("Strongly Disagree", "Disagree", "Neutral", "Agree", "Strongly Agree")
bar_colors <- c("red", "green", "blue", "orange", "purple")
barplot(Ques17.freq,
        col=bar_colors,
        ylab = "Frequency",
        names.arg = x_labels,
        xlab = "",
        ylim = c(0,30),
        main = "Are you comfortable with your learning mode right now? "
        )
text(x = barplot(Ques17.freq, plot = FALSE), y = Ques17.freq, labels = Ques17.freq, pos = 3, col = "black")
legend("topright", legend = x_labels, fill = bar_colors, cex = 0.6)


Ques18.freq <- table(Ques18)
pie(Ques18.freq,
    main = "Would you consider changing your current learning mode?"
    )
library(plotrix)
pie3D(Ques18.freq,labels=names(Ques18.freq),main="Would you consider changing your current learning mode?",explode=0.1)
