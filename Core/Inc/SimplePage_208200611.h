/* **********************************
 *	SimplePage 简易GUI框架
 *	by 邓君卓 208200611
 * ********************************** */

#ifndef _H_LIBSIMPLEPAGE_
#define _H_LIBSIMPLEPAGE_
#include "main.h"

#define _new_(X) (X*)malloc(sizeof(X))
#define _newN_(X,N) (X*)malloc(sizeof(X)*N)

struct Label;
struct SimplePage;

typedef struct Label Label;
typedef struct SimplePage SimplePage;
typedef struct UserInputHandler UserInputHandler;

struct UserInputHandler{
	void (*Up)();
	void (*Down)();
	void (*Left)();
	void (*Right)();
	void (*Mid)();
	void (*Set)();
	void (*Reset)();
};

struct Label {
	char *Text;
	u8 Selectable, Selected, Changed, Centered;
	u8 LastLen;
	SimplePage *LinkTo;
	void (*OnClick)(Label*);
};

struct SimplePage {
	char *Title;
	u8 SelectedIndex;
	u8 Changed;
	u8 SelfRender;
	Label *Line1, *Line2, *Line3;
	void (*PendingRawInput)(); //简化的输入消息队列，长度为1
	void (*PendingFunCall)(Label*); //简化的UI消息队列，长度为1
	void (*BeforeUpdate)(SimplePage*);
	Label *LastTriggered;
	SimplePage *Prev;
	UserInputHandler *InputHandler;
};

void UpdatePage(SimplePage*);
void MenuSelectNext(SimplePage*);
void MenuSelectPrev(SimplePage*);
void MenuClick(SimplePage*);
void RenderPage(SimplePage*);

Label* EmptyLabel();

SimplePage* EmptyPage();

#endif
