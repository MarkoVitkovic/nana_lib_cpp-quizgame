#include <nana/gui.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/textbox.hpp>
#include <nana/gui/msgbox.hpp>
#include <nana/gui/place.hpp>
#include "Resource.h"
#include <stack>


using namespace nana;

class forms {
private:

	const size WINDOW_SIZE = { 500, 350 };
	const size WINDOW_SIZE2 = { 700, 450 };
	static constexpr bool set_min_size = false;
	static constexpr bool set_max_size = true;
	form fm;
	form que;
	std::stack<std::string> question;
	std::stack<std::string> answers;

public:
	
	forms() 
	{
		fm.size(WINDOW_SIZE);
		que.size(WINDOW_SIZE2);
		API::track_window_size(fm, WINDOW_SIZE, set_min_size);
		API::track_window_size(fm, WINDOW_SIZE, set_max_size);
		API::track_window_size(que, WINDOW_SIZE2, set_min_size);
		API::track_window_size(que, WINDOW_SIZE2, set_max_size);
		fm.caption(GAME_TITLE);
		que.caption(GAME_TITLE);
	}
	void StackPush()
	{
		question.push(EMPTY);
		question.push(QUESTION_ONE);
		question.push(QUESTION_TWO);
		question.push(QUESTION_THREE);
		question.push(QUESTION_FOUR);
		question.push(QUESTION_FIVE);
		question.push(QUESTION_SIX);
		question.push(QUESTION_SEVEN);
		question.push(QUESTION_EIGHT);
		question.push(QUESTION_NINE);
		question.push(QUESTION_TEN);
		answers.push(ANSWER_ONE);
		answers.push(ANSWER_TWO);
		answers.push(ANSWER_THREE);
		answers.push(ANSWER_FOUR);
		answers.push(ANSWER_FIVE);
		answers.push(ANSWER_SIX);
		answers.push(ANSWER_SEVEN);
		answers.push(ANSWER_EIGHT);
		answers.push(ANSWER_NINE);
		answers.push(ANSWER_TEN);
	}
	void Start()
	{
		std::string a;
		//buttons for forms
		button start{ fm, nana::rectangle(130, 270, 100 , 30) };
		button quit{ fm, nana::rectangle(280, 270, 100, 30) };
		button check{ que, nana::rectangle(300, 350, 100, 30) };
		start.caption(START); 
		quit.caption(QUIT);
		check.caption(CHECH);
		API::effects_bground(start, effects::bground_transparent(0), 0);
		API::effects_bground(quit, effects::bground_transparent(0), 0);
		API::effects_bground(check, effects::bground_transparent(0), 0);
		start.fgcolor(colors::white);
		quit.fgcolor(colors::white);
		check.fgcolor(colors::white);
		
		//label
		label question1{ que, nana::rectangle(155, 100, 400 , 100) };
		question1.fgcolor(colors::white);
		API::effects_bground(question1, effects::bground_transparent(0), 0);
		question1.text_align(align::center);
		question1.format(true);


		//input box
		textbox tb(que, nana::rectangle{ 200, 300 ,300,30 });
		API::effects_bground(tb, effects::bground_transparent(0), 0);
		tb.fgcolor(colors::white);
		tb.text_align(align::center);

		//msgbox
		msgbox correct{ MSGBOX_CORRECT_TITLE };
		msgbox wrong{ MSGBOX_WRONG_TITLE };
		msgbox win{ MSGBOX_WIN_TITLE };
		correct << MSGBOX_CORRECT;
		wrong << MSGBOX_WRONG;
		win << MSGBOX_WIN;

		//Background
		nana::paint::image mainImg(IMG_1);
		nana::paint::image secImg(IMG_2);
		drawing dw(fm);
		drawing dwQue(que);
		dw.draw([&mainImg](nana::paint::graphics & graph)
		{
			if (mainImg.empty()) return;
			mainImg.paste(graph, nana::point{});
		});
		dw.update();
		dwQue.draw([&secImg](nana::paint::graphics & graph)
		{
			if (secImg.empty()) return;
			secImg.paste(graph, nana::point{});
		});
		dwQue.update();


		//button functionality
		quit.events().click([] {
			API::exit_all();
		});
		start.events().click([this] {
			que.show();
		});
		a = question.top();
		question.pop();
		question1.caption(a);
		check.events().click([&question1, &tb, &check, &a, correct, wrong, win, this] {
			check.enabled(false);
			if (tb.text() == answers.top()) {
				if (correct.show() == msgbox::pick_ok || msgbox::pick_cancel) 
				{
					check.enabled(true);
					tb.reset("");
				}
				a = question.top();
				question.pop();
				question1.caption(a);
				answers.pop();
			}
			else {
				if (wrong.show() == msgbox::pick_ok || msgbox::pick_cancel)
				{
					check.enabled(true);
					tb.reset("");
				}
				question1.caption(a);
			}
			if (question.empty()) {
				if (win.show() == msgbox::pick_ok || msgbox::pick_cancel)
				{
					check.enabled(true);
					tb.reset("");
					API::exit_all();
				}
			}
		});
		
		fm.show();
		exec();
	}
};

int main()
{
	forms comp;
	comp.StackPush();
	comp.Start();
}