#include "Model.h"
#include "View.h"

class App
{
   
public:
   Model *m;
   View *v;
   App(Evas_Object *parent)
   {
      m = new Model(1000);
      v = new View(parent);
      
      v->sInitShow.Connect(m, &Model::Init);
      v->sMove.Connect(m, &Model::MoveStep);
      m->sShow.Connect(v, &View::Show);
      m->sUpdate.Connect(v, &View::Update);
      v->Init();
   }

};

int main(int argc, char **argv)
{
   elm_init(argc, argv);
   Evas_Object *win;
   elm_theme_overlay_add(NULL, "./genlist.edj");
   elm_config_focus_highlight_enabled_set(EINA_TRUE);
   elm_config_focus_highlight_animate_set(EINA_TRUE);
   elm_config_focus_autoscroll_mode_set(ELM_FOCUS_AUTOSCROLL_MODE_BRING_IN);

   win = elm_win_util_standard_add("lazyloading genlist",
      "Lazy Loading Genlist");
   elm_win_autodel_set(win, EINA_TRUE);
   
   App app(win);

   elm_win_resize_object_add(win, app.v->gl);
   evas_object_resize(win, 500, 500);
   evas_object_show(app.v->gl);
   evas_object_show(win);

   elm_run();
   elm_shutdown();
   
   return 0;
}