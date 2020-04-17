#include <nana/gui.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/msgbox.hpp>

int main()
{
	using namespace nana;

	//Define a form.
	form fm;
	form sec;
	form thrid;
	nana::API::track_window_size(fm, { 500,400 }, false); //minimum
	nana::API::track_window_size(fm, { 700,600 }, true); //maximum
	nana::API::track_window_size(sec, { 700,400 }, false); //minimum
	nana::API::track_window_size(sec, { 1000,600 }, true); //maximum
	fm.caption("QuizGame");

	//Define a label and display a text.
	label lab{ fm, "<bold size=30>Quiz Game</>" };
	lab.text_align(align::center);
	label question{ sec, "<bold size=30>Tko je Rus?</>" };
	question.text_align(align::center);
	lab.format(true);
	question.format(true);

	//Define a msgbox
	msgbox m(sec, "Wrong answer", msgbox::ok);
	m << "Wrong answer, try again.";
	msgbox mc(sec, "Correct answer", msgbox::ok);
	mc << "Correct answer, nice!";

	//Define a button and answer the click event.
	button btn{ fm, "Quit" };
	btn.events().click([&fm] {
		fm.close();
	});
	button btn2{ fm, "Start" };
	btn2.events().click([&sec, &fm] {
		sec.show();
		fm.close();
	});
	btn2.bgcolor(color_rgb(0x7ACC));
	btn2.fgcolor(colors::white);

	//Define a button on second form
	button q1{ sec, "Covjek" };
	q1.events().click([&sec, &thrid, &mc] {
		mc.show();
		thrid.show();
		sec.close();
	});
	button q2{ sec, "Medo" };
	q2.events().click([&sec, &m] {
		m.show();
	});
	button q3{ sec, "Konj" };
	q3.events().click([&sec, &m] {
		m.show();
	});
	button q4{ sec, "Zmaj" };
	q4.events().click([&sec, &m] {
		m.show();
	});
	button quit{ sec, "Quit game" };
	quit.events().click([&sec] {
		sec.close();
	});

	//Layout management
	fm.div("vert <><<><weight=100% text><>><><weight=30<><button><>><>");
	fm["text"] << lab;
	fm["button"] << btn2;
	fm["button"] << btn;
	fm.collocate();
	sec.div("vert <><<><weight=100% text><>><><weight=30<><button><>><>");
	sec["text"] << question;
	sec["button"] << q1;
	sec["button"] << q2;
	sec["button"] << q3;
	sec["button"] << q4;
	sec["button"] << quit;
	sec.collocate();

	//Show the form
	fm.show();

	//Start to event loop process, it blocks until the form is closed.
	exec();
}