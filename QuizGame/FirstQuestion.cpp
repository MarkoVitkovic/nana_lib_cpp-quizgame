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

	//Define a label and display a text.
	label lab{ fm, "<bold size=16>Quiz Game</>" };
	label question{ sec, "Tko je Rus?" };
	lab.format(true);
	question.format(true);

	//Define a msgbox
	msgbox m(sec, "Wrong answer", msgbox::ok);
	m << "Wrong answer, try again.";

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

	//Define a button on second form
	button q1{ sec, "Covjek" };
	q1.events().click([&sec, &m] {
		m.show();
	});
	button q2{ sec, "Medo" };
	q2.events().click([&sec] {
		
	});
	button q3{ sec, "Konj" };
	q3.events().click([&sec] {

	});
	button q4{ sec, "Zmaj" };
	q4.events().click([&sec] {

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