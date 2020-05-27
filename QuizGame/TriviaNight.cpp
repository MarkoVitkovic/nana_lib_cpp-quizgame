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
	form questionOne;
	form questionTwo;
	form questionThree;

	//Forms size
	nana::API::track_window_size(fm, { 500,350 }, false); //minimum
	nana::API::track_window_size(fm, { 500,350 }, true); //maximum
	nana::API::track_window_size(questionOne, { 700,450 }, false); //minimum
	nana::API::track_window_size(questionOne, { 700,450 }, true); //maximum
	nana::API::track_window_size(questionTwo, { 700,450 }, false); //minimum
	nana::API::track_window_size(questionTwo, { 700,450 }, true); //maximum
	nana::API::track_window_size(questionThree, { 700,450 }, false); //minimum
	nana::API::track_window_size(questionThree, { 700,450 }, true); //maximum
	fm.caption("Trivia Night");
	questionOne.caption("Trivia Night");
	questionTwo.caption("Trivia Night");
	questionThree.caption("Trivia Night");
	

	//Define a label and display a text.
	label question1{ questionOne, nana::rectangle(155, 100, 400 , 100) };
	question1.fgcolor(colors::white);
	API::effects_bground(question1, effects::bground_transparent(0), 0);
	question1.text_align(align::center);
	question1.format(true);
	question1.caption("<size=25>Tko je rus, gdje je odsjeo i koja mu je domovina?</>");
	

	//Define a msgbox
	msgbox m(fm, "Wrong answer", msgbox::ok);
	m << "Wrong answer, try again.";
	msgbox mc(questionOne, "Correct answer", msgbox::ok);
	mc << "Correct answer, nice!";
	nana::msgbox correct{ "Correct answer" };
	correct << "Correct answer, nice!";
	nana::msgbox wrong{ "Wrong answer" };
	wrong << "Wrong answer, try again.";


	//Define a button and answer the click event(main form).
	button btn{ fm, nana::rectangle(130, 270, 100 , 30) };
	btn.events().click([&questionOne, &fm] {
		questionOne.show();
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


	//Define a button on questionOne form
	button q1a1{ questionOne, nana::rectangle(145, 270, 200 , 40) };
	q1a1.events().click([&questionOne, &correct, &questionTwo] {
		correct.show();
		questionTwo.show();
		questionOne.close();
	});
	q1a1.caption("Man");
	API::effects_bground(q1a1, effects::bground_transparent(0), 0);
	q1a1.fgcolor(colors::white);

	button q1a2{ questionOne, nana::rectangle(365, 270, 200 , 40) };
	q1a2.events().click([&wrong] {
		wrong.show();
	});
	q1a2.caption("Rus");
	API::effects_bground(q1a2, effects::bground_transparent(0), 0);
	q1a2.fgcolor(colors::white);

	button q1a3{ questionOne, nana::rectangle(145, 330, 200 , 40) };
	q1a3.events().click([&wrong] {
		wrong.show();
	});
	q1a3.caption("Rus");
	API::effects_bground(q1a3, effects::bground_transparent(0), 0);
	q1a3.fgcolor(colors::white);

	button q1a4{ questionOne, nana::rectangle(365, 330, 200 , 40) };
	q1a4.events().click([&wrong] {
		wrong.show();
	});
	q1a4.caption("Rus");
	API::effects_bground(q1a4, effects::bground_transparent(0), 0);
	q1a4.fgcolor(colors::white);

	//Define a button on questionTwo form
	button q2a1{ questionTwo, nana::rectangle(145, 270, 200 , 40) };
	q2a1.events().click([&questionTwo, &correct, &questionThree] {
		correct.show();
		questionThree.show();
		questionTwo.close();
	});
	q2a1.caption("Man");
	API::effects_bground(q2a1, effects::bground_transparent(0), 0);
	q2a1.fgcolor(colors::white);

	button q2a2{ questionTwo, nana::rectangle(365, 270, 200 , 40) };
	q2a2.events().click([&wrong] {
		wrong.show();
	});
	q2a2.caption("Rus");
	API::effects_bground(q2a2, effects::bground_transparent(0), 0);
	q2a2.fgcolor(colors::white);

	button q2a3{ questionTwo, nana::rectangle(145, 330, 200 , 40) };
	q2a3.events().click([&wrong] {
		wrong.show();
	});
	q2a3.caption("Rus");
	API::effects_bground(q2a3, effects::bground_transparent(0), 0);
	q2a3.fgcolor(colors::white);

	button q2a4{ questionTwo, nana::rectangle(365, 330, 200 , 40) };
	q1a4.events().click([&wrong] {
		wrong.show();
	});
	q2a4.caption("Rus");
	API::effects_bground(q2a4, effects::bground_transparent(0), 0);
	q2a4.fgcolor(colors::white);
	

	//Show the form
	fm.show();

	//Backgrounds
	nana::paint::image mainImg("C:\\Users\\Korisnik\\source\\repos\\QuizGame\\QuizGame\\firstpage.jpg");
	drawing dw(fm);
	dw.draw([&mainImg](nana::paint::graphics & graph)
	{
		if (mainImg.empty()) return;
		mainImg.paste(graph, nana::point{});
	});
	dw.update();

	nana::paint::image Img("C:\\Users\\Korisnik\\source\\repos\\QuizGame\\QuizGame\\Question.jpg");
	drawing dw1(questionOne);
	dw1.draw([&Img](nana::paint::graphics & graph)
	{
		if (Img.empty()) return;
		Img.paste(graph, nana::point{});
	});
	dw1.update();

	drawing dw2(questionTwo);
	dw2.draw([&Img](nana::paint::graphics & graph)
	{
		if (Img.empty()) return;
		Img.paste(graph, nana::point{});
	});
	dw2.update();

	drawing dw3(questionThree);
	dw3.draw([&Img](nana::paint::graphics & graph)
	{
		if (Img.empty()) return;
		Img.paste(graph, nana::point{});
	});
	dw3.update();

	//Start to event loop process, it blocks until the form is closed.
	exec();
}
