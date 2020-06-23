#include <nana/gui.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/textbox.hpp>
#include <nana/gui/msgbox.hpp>
#include <nana/gui/place.hpp>
#include "Resource.h"

using namespace nana;
class forms {
private:

	const size WINDOW_SIZE = { 500, 350 };
	const size WINDOW_SIZE2 = { 700, 450 };
	static constexpr bool set_min_size = false;
	static constexpr bool set_max_size = true;
	form fm;
	form que;

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
	void Start()
	{
		//buttons for forms
		button start{ fm, nana::rectangle(130, 270, 100 , 30) };
		button quit{ fm, nana::rectangle(280, 270, 100, 30) };
		button check{ que, nana::rectangle(300, 350, 100, 30) };
		start.caption(START); 
		quit.caption(QUIT);
		API::effects_bground(start, effects::bground_transparent(0), 0);
		API::effects_bground(quit, effects::bground_transparent(0), 0);
		start.fgcolor(colors::white);
		quit.fgcolor(colors::white);
		
		//label
		label question1{ que, nana::rectangle(300, 100, 400 , 100) };
		question1.caption(QUESTION_ONE);

		//input box
		textbox tb(que, nana::rectangle{ 200, 300 ,300,30 });		

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
		check.events().click([&question1, &tb, &check] {
			for (int i = 0; i < 10; i++) {
				if (tb.text() == QUESTION_EIGHT_ANSWER_FOUR) {
					question1.caption(QUESTION_EIGHT);
					tb.reset();
				}
				else {
					question1.caption(QUESTION_EIGHT_ANSWER_FOUR);
					check.enabled(false);
				}
				tb.clear_undo();
			}
			
		});
		fm.show();
		exec();
	}
};

int main()
{
	forms comp;
	comp.Start();
}