#include <nana/gui.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/msgbox.hpp>
#include <nana/gui/place.hpp>


int main()
{
	using namespace nana;

	//Define a form.
	form fm;
	form sec;
	form thrid;

	//Forms size
	nana::API::track_window_size(fm, { 500,350 }, false); //minimum
	nana::API::track_window_size(fm, { 500,350 }, true); //maximum
	nana::API::track_window_size(sec, { 700,400 }, false); //minimum
	nana::API::track_window_size(sec, { 1000,600 }, true); //maximum
	fm.caption("Trivia Night");
	

	//Define a label and display a text.
	label question{ sec, "<bold size=30>Tko je Rus?</>" };
	API::effects_bground(question, effects::bground_transparent(0), 0);
	question.text_align(align::center);
	question.format(true);
	

	//Define a msgbox
	msgbox m(sec, "Wrong answer", msgbox::ok);
	m << "Wrong answer, try again.";
	msgbox mc(sec, "Correct answer", msgbox::ok);
	mc << "Correct answer, nice!";


	//Define a button and answer the click event(main form).
	button btn{ fm, nana::rectangle(130, 270, 100 , 30) };
	btn.events().click([&sec, &fm] {
		sec.show();
	});
	btn.caption("Start"); 
	API::effects_bground(btn, effects::bground_transparent(0), 0);
	btn.fgcolor(colors::white);

	button btn2{ fm, nana::rectangle(280, 270, 100, 30)};
	btn2.events().click([&fm] {
		fm.close();
	});
	btn2.caption("Quit");
	API::effects_bground(btn2, effects::bground_transparent(0), 0);
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
	q3.events().click([&sec, &m, &fm] {
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
	sec.div("vert <><<><weight=100% text><>><><weight=30<><button><>><>");
	sec["text"] << question;
	sec["button"] << q1 << q2;
	sec["button"] << q3 << q4;
	sec["button"] << quit;
	sec.collocate();


	
	//Show the form
	fm.show();

	nana::paint::image mainImg("C:\\Users\\Korisnik\\source\\repos\\QuizGame\\QuizGame\\firstpage.jpg");
	drawing dw(fm);
	dw.draw([&mainImg](nana::paint::graphics & graph)
	{
		if (mainImg.empty()) return;
		mainImg.paste(graph, nana::point{});
	});
	dw.update();

	nana::paint::image Img("C:\\Users\\Korisnik\\source\\repos\\QuizGame\\QuizGame\\Question.jpg");
	drawing dw1(sec);
	dw1.draw([&Img](nana::paint::graphics & graph)
	{
		if (Img.empty()) return;
		Img.paste(graph, nana::point{});
	});
	dw1.update();

	//Start to event loop process, it blocks until the form is closed.
	exec();
}