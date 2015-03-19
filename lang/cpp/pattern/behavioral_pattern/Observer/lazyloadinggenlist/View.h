#ifndef _VIEW_H
#define _VIEW_H
#include "priv.h"
#include <Elementary.h>

#define F printf(__PRETTY_FUNCTION__); printf("\n")
#define WEIGHT evas_object_size_hint_weight_set
#define ALIGN_ evas_object_size_hint_align_set
#define EXPAND(X) WEIGHT((X), EVAS_HINT_EXPAND, EVAS_HINT_EXPAND)
#define FILL(X) ALIGN_((X), EVAS_HINT_FILL, EVAS_HINT_FILL)

class View
{
   Elm_Genlist_Item_Class *itc1;
   static char *gl_text_get(void *data, Evas_Object *obj,
                            const char *part);
   static Evas_Object *gl_content_get(void *data,
                                      Evas_Object *obj, const char *part);
   
   static Eina_Bool gl_state_get(void *data ,
                       Evas_Object *obj ,
                       const char *part );

   static void gl_scroll(void *data, Evas_Object *obj,
      void *event_info)
   {
      F;
      View *v = (View *) data;

      if (v->dir == UP)
      {
         v->sMove(UP);
      }
      else if (v->dir == DOWN)
      {
         v->sMove(DOWN);
      }
   }
  /* static void gl_scroll_down(void *data, Evas_Object *obj,
      void *event_info)
   {
      F;
   }*/
   static void gl_key_down_cb(void *data,
      Evas *e, Evas_Object *obj, void *ei)
   {
      Evas_Event_Key_Down *k = (Evas_Event_Key_Down *)ei;
      View *v = (View *)data;
      F;
      if (!strcmp(k->keyname, "Up"))
      {
         v->dir = UP;
      }
      else if (!strcmp(k->keyname, "Down"))
      {
         v->dir = DOWN;
      }
   }
   void _add_callbacks()
   {
      evas_object_event_callback_add(gl,
         EVAS_CALLBACK_KEY_DOWN, gl_key_down_cb,
         this);
      evas_object_smart_callback_add(gl,
         "scroll,anim,start", gl_scroll, this);
   }
public:
   Signal0< > sInitShow;
   Signal1< Direction > sMove;
   Direction dir;
   void Init()
   {
      _add_callbacks();
      sInitShow();
      cout << "calling sInitShow\n";
   }
   void Show(DataChangeInfo **, bool);
   //Evas_Object *sc;
   Evas_Object *gl;
   View(Evas_Object *parent);
   ~View()
   {
      evas_object_event_callback_del(gl, EVAS_CALLBACK_KEY_DOWN,
         gl_key_down_cb);
      elm_genlist_item_class_free(itc1);

   }

   void Update(DataChangeInfo **dci);

};

#endif