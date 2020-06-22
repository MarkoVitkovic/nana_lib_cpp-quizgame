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
	static constexpr bool set_min_size = false;
	static constexpr bool set_max_size = true;
	form fm;
	form que;

public:
	
	forms() 
	{
		fm.size(WINDOW_SIZE);
		API::track_window_size(fm, WINDOW_SIZE, set_min_size);
		API::track_window_size(fm, WINDOW_SIZE, set_max_size);
		fm.caption(GAME_TITLE);
	}
	void Start()
	{
		//buttons for foms
		button start{ fm, nana::rectangle(130, 270, 100 , 30) };
		button quit{ fm, nana::rectangle(280, 270, 100, 30) };
		button check{ que, nana::rectangle(280, 270, 100, 30) };
		start.caption(START); 
		quit.caption(QUIT);
		API::effects_bground(start, effects::bground_transparent(0), 0);
		API::effects_bground(quit, effects::bground_transparent(0), 0);
		start.fgcolor(colors::white);
		quit.fgcolor(colors::white);
		
		//label
		label question1{ que, nana::rectangle(155, 100, 400 , 100) };
		question1.caption(QUESTION_ONE);

		//input box
		textbox tb(que, nana::rectangle{ 10,10,100,30 });		

		//Background
		nana::paint::image mainImg(IMG_1);
		drawing dw(fm);
		dw.draw([&mainImg](nana::paint::graphics & graph)
		{
			if (mainImg.empty()) return;
			mainImg.paste(graph, nana::point{});
		});
		dw.update();


		//button functionality
		quit.events().click([] {
			API::exit_all();
		});
		start.events().click([this] {
			que.show();
		});
		check.events().click([&question1, &tb] {
			for (int i = 0; i < 10; i++) {
				if (tb.text() == QUESTION_EIGHT_ANSWER_FOUR) {
					question1.caption(QUESTION_EIGHT);
				}
				else {
					question1.caption(QUESTION_EIGHT_ANSWER_FOUR);
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
	comp.Start();
}