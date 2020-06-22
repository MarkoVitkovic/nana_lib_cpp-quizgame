//#include "Form.h"
//#include "Resource.h"
//#include <nana/gui.hpp>
//#include <nana/gui/widgets/label.hpp>
//#include <nana/gui/widgets/button.hpp>
//#include <nana/gui/msgbox.hpp>
//#include <nana/gui/place.hpp>
//
//
//
//form Form::GetInstanceOfForm()
//{
//	return GameForm;
//}
//
//Form::Form(std::string title)
//{
//	const size WINDOW_SIZE = { 500, 350 };
//	GameForm.size(WINDOW_SIZE);
//	API::track_window_size(GameForm, WINDOW_SIZE, false); //minimum
//	API::track_window_size(GameForm, WINDOW_SIZE, true); //maximum
//	GameForm.caption(title);
//}
//
//void Form::SetFormButtonsStart(rectangle rect, form nextForm, std::string cap, color col)
//{
//	button btn{ GameForm, nana::rectangle(130, 270, 100 , 30) };
//	btn.caption("ASDSDA"); 
//	API::effects_bground(btn, effects::bground_transparent(0), 0);
//	btn.fgcolor(colors::white);
//}
//
//void Form::SetFormButtonsClose(rectangle rect, std::string cap, color col)
//{
//	button btn{ GameForm, rect };
//	btn.caption(cap);
//	//API::effects_bground(btn, effects::bground_transparent(0), 0);
//	btn.fgcolor(col);
//}
//
//void Form::SetQuestion(rectangle rect, color col, align ali, std::string cap)
//{
//	label question{ GameForm,rect };
//	question.fgcolor(col);
//	API::effects_bground(question, effects::bground_transparent(0), 0);
//	question.text_align(ali);
//	question.format(true);
//	question.caption(cap);
//}
//
//void Form::SetBackground(nana::paint::image img)
//{
//	/*drawing dw(GameForm);
//	dw.draw([&img](nana::paint::graphics & graph)
//	{
//		if (img.empty()) return;
//		img.paste(graph, nana::point{});
//	});
//	dw.update();*/
//}
//
//void Form::showForm()
//{
//	GameForm.show();
//}
//
//
//Form::~Form()
//{
//}
//
//int main()
//{
//	Form gameForm(GAME_TITLE);
//	nana::paint::image mainImg(IMG_1);
//	gameForm.SetBackground(mainImg);
//	gameForm.SetFormButtonsStart(nana::rectangle(130, 270, 100, 30), gameForm.GetInstanceOfForm(), START, colors::white);
//	gameForm.SetFormButtonsClose(nana::rectangle(280, 270, 100, 30), QUIT, colors::white);
//	gameForm.showForm();
//	exec();
//}
