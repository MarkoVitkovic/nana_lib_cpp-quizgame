#include <nana/gui.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/msgbox.hpp>
#include <nana/gui/place.hpp>
#include "Resource.h"
#include "Form.h"

using namespace nana;


int main()
{
	Form gameForm("TITLEEEE");
	nana::paint::image mainImg(IMG_1);
	gameForm.SetBackground(mainImg);
gameForm.SetFormButtonsStart(nana::rectangle(130, 270, 100, 30), gameForm.GetInstanceOfForm(), START, colors::white);
	gameForm.SetFormButtonsClose(nana::rectangle(280, 270, 100, 30), gameForm.GetInstanceOfForm(), QUIT, colors::white);
	gameForm.showForm();


	////
	//////Define a forms.
	////form fm;
	////form questionOne;


	//////Forms size
	////nana::API::track_window_size(fm, { 500,350 }, false); //minimum
	////nana::API::track_window_size(fm, { 500,350 }, true); //maximum
	////nana::API::track_window_size(questionOne, { 700,450 }, false); //minimum
	////nana::API::track_window_size(questionOne, { 700,450 }, true); //maximum
	////fm.caption(GAME_TITLE);
	////questionOne.caption(GAME_TITLE);


	//////Define a label and display a text. Question One
	////label question1{ questionOne, nana::rectangle(155, 100, 400 , 100) };
	////question1.fgcolor(colors::white);
	////API::effects_bground(question1, effects::bground_transparent(0), 0);
	////question1.text_align(align::center);
	////question1.format(true);
	////question1.caption(QUESTION_ONE);
	////


	//////Define a msgbox
	////nana::msgbox correct{ MSGBOX_CORRECT_TITLE };
	////correct << MSGBOX_CORRECT;
	////nana::msgbox wrong{ MSGBOX_WRONG_TITLE };
	////wrong << MSGBOX_WRONG;
	////nana::msgbox win{ MSGBOX_WIN_TITLE };
	////win << MSGBOX_WIN;




	//////Define a button and answer the click event(main form).
	////button btn{ fm, nana::rectangle(130, 270, 100 , 30) };
	////btn.events().click([&questionOne, &fm] {
	////	questionOne.show();
	////});
	////btn.caption(START); 
	////API::effects_bground(btn, effects::bground_transparent(0), 0);
	////btn.fgcolor(colors::white);

	////button btn2{ fm, nana::rectangle(280, 270, 100, 30)};
	////btn2.events().click([&fm] {
	////	fm.close();
	////});
	////btn2.caption(QUIT);
	////API::effects_bground(btn2, effects::bground_transparent(0), 0);
	////btn2.fgcolor(colors::white);


	//////Define a button on questionOne form
	////button q1a1{ questionOne, nana::rectangle(145, 270, 200 , 40) };
	////q1a1.events().click([&questionOne, &correct,] {
	////	correct.show();
	////	
	////	questionOne.close();
	////});
	////q1a1.caption(QUESTION_ONE_ANSWER_ONE);
	////API::effects_bground(q1a1, effects::bground_transparent(0), 0);
	////q1a1.fgcolor(colors::white);

	////button q1a2{ questionOne, nana::rectangle(365, 270, 200 , 40) };
	////q1a2.events().click([&wrong] {
	////	wrong.show();
	////});
	////q1a2.caption(QUESTION_ONE_ANSWER_TWO);
	////API::effects_bground(q1a2, effects::bground_transparent(0), 0);
	////q1a2.fgcolor(colors::white);

	////button q1a3{ questionOne, nana::rectangle(145, 330, 200 , 40) };
	////q1a3.events().click([&wrong] {
	////	wrong.show();
	////});
	////q1a3.caption(QUESTION_ONE_ANSWER_THREE);
	////API::effects_bground(q1a3, effects::bground_transparent(0), 0);
	////q1a3.fgcolor(colors::white);

	////button q1a4{ questionOne, nana::rectangle(365, 330, 200 , 40) };
	////q1a4.events().click([&wrong] {
	////	wrong.show();
	////});
	////q1a4.caption(QUESTION_ONE_ANSWER_FOUR);
	////API::effects_bground(q1a4, effects::bground_transparent(0), 0);
	////q1a4.fgcolor(colors::white);

	

	//Show the form

	////Backgrounds
	//nana::paint::image mainImg(IMG_1);
	//drawing dw(fm);
	//dw.draw([&mainImg](nana::paint::graphics & graph)
	//{
	//	if (mainImg.empty()) return;
	//	mainImg.paste(graph, nana::point{});
	//});
	//dw.update();

	//nana::paint::image Img(IMG_2);
	//drawing dw1(questionOne);
	//dw1.draw([&Img](nana::paint::graphics & graph)
	//{
	//	if (Img.empty()) return;
	//	Img.paste(graph, nana::point{});
	//});
	//dw1.update();

	

	//Start to event loop process, it blocks until the form is closed.
	exec();
}
