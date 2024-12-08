#include "term.h"
#include <gtest.h>

TEST(translator, stuff) {
	Translator thing("1+(2+3*4)/5+6*7*(8+(9+0))");
	EXPECT_EQ(717.8, thing.getAnswer());
}

TEST(translator, AddCorrectly) {
	Translator tr("1+2");
	EXPECT_EQ(3, tr.getAnswer());
}

TEST(translator, SubCorrectly) {
	Translator tr("2-1");
	EXPECT_EQ(1, tr.getAnswer());
}

TEST(translator, MulCorrectly) {
	Translator tr("3*5");
	EXPECT_EQ(15, tr.getAnswer());
}

TEST(translator, DivCorrectly) {
	Translator tr("15/3");
	EXPECT_EQ(5, tr.getAnswer());
}

TEST(translator, CantDivBy0) {
	Translator tr("5/0");
	ASSERT_ANY_THROW(tr.getAnswer());
}

TEST(translator, BracketsPriority) {
	Translator tr("2*(3+4)");
	EXPECT_EQ(14, tr.getAnswer());
}

TEST(translator, FloatingNumbersWith0) {
	Translator tr("0.2+0.3");
	EXPECT_EQ(0.5, tr.getAnswer());
}

TEST(translator, FloatingIntNumbers) {
	Translator tr("2.+3.");
	EXPECT_EQ(5, tr.getAnswer());
}

TEST(translator, FloatingNumbers) {
	Translator tr("2.2+0.3");
	EXPECT_EQ(2.5, tr.getAnswer());
}

TEST(translator, UnaryMinusWithoutBracketsAdd) {
	Translator tr("-5+5");
	EXPECT_EQ(0, tr.getAnswer());
}

TEST(translator, UnaryMinusWithoutBracketsMul) {
	Translator tr("-5*3");
	EXPECT_EQ(-15, tr.getAnswer());
}

TEST(translator, UnaryMinusWithoutBracketsDiv) {
	Translator tr("-5/5");
	EXPECT_EQ(-1, tr.getAnswer());
}

TEST(translator, UnaryMinusWithBrackets) {
	Translator tr("5+(-5)");
	EXPECT_EQ(0, tr.getAnswer());
}

TEST(translator, ThrowsWhenClosingBracketIsFirst) {
	Translator tr(")5+5(");
	ASSERT_ANY_THROW(tr.getAnswer());
}

TEST(translator, ThrowsWhenDifferentAmountOfBrackets) {
	Translator tr("((5+5)");
	ASSERT_ANY_THROW(tr.getAnswer());
}