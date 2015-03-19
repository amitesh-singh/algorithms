#include "View.h"

View::View(Evas_Object *parent)
{
  /* sc = elm_scroller_add(parent);
   FILL(sc);
   EXPAND(sc);
   evas_object_show(sc);*/
   gl = elm_genlist_add(parent);
   elm_genlist_homogeneous_set(gl, 1);
   FILL(gl); EXPAND(gl);

   itc1 = elm_genlist_item_class_new();
   itc1->item_style     = "default";
   itc1->func.text_get = gl_text_get;
   itc1->func.content_get  = gl_content_get;
   itc1->func.state_get = gl_state_get;
   itc1->func.del       = NULL;
   /*elm_genlist_item_append(gl, itc1,
            NULL,
            NULL,
            ELM_GENLIST_ITEM_NONE,
            NULL,
            NULL);*/
   //elm_genlist_item_class_free(itc1);
   /*elm_object_content_set(sc, gl);*/
}

char * View::gl_text_get(void *data,
                       Evas_Object *obj,
                       const char *part)
{
   char *str = (char *)data;
   if (!str)
      return NULL;
   printf("part: %s\n", part);

   if (!strcmp(part, "elm.text.telephone"))
     {
        return strdup(str);
     }
   else if (!strcmp(part, "elm.text.name"))
     {
        return strdup("Oye Oye!");
     }
   else if (!strcmp(part, "elm.text.callno"))
     {
        return strdup("(10)");
     }
}

Evas_Object * View::gl_content_get(void *data EINA_UNUSED,
                                   Evas_Object *obj, const char *part)
{
    char buf[PATH_MAX];

   if (!strcmp(part, "elm.swallow.end"))
     {
        Evas_Object *ic = elm_icon_add(obj);
        elm_image_file_set(ic, "unnamed.png", NULL);
        evas_object_size_hint_aspect_set(ic, 
           EVAS_ASPECT_CONTROL_VERTICAL, 1, 1);
        return ic;
     }
   else if (!strcmp(part, "elm.swallow.icon"))
     {
        Evas_Object *ic = elm_icon_add(obj);
        elm_image_file_set(ic, "photo.jpg", NULL);
        //elm_image_file_set(ic, "unnamed.png", NULL);
        evas_object_size_hint_aspect_set(ic,
           EVAS_ASPECT_CONTROL_VERTICAL, 1, 1);
        return ic;
     }
}

Eina_Bool View::gl_state_get(void *data ,
                       Evas_Object *obj ,
                       const char *part )
{
   return EINA_FALSE;
}

void View::Show(DataChangeInfo **dci, bool refresh)
{
   DataChangeInfo *dc = *dci;
   if (refresh)
   {
      deque< Data *> *d = dc->d;
      for(int i = 0; i < d->size(); ++i)
      {
         cout << i << "\n";
         elm_genlist_item_append(gl, itc1,
            NULL,
            NULL,
            ELM_GENLIST_ITEM_NONE,
            NULL,
            NULL);
      }
      delete dc;
   }
   else
   {
   }
}
void View::Update(DataChangeInfo **dci)
{
   DataChangeInfo *dc = *dci;

   if (dir == UP)
   {
      cerr << __FUNCTION__ << ":" << "Up" << endl;
      elm_genlist_item_insert_before(gl,
         itc1, NULL, NULL, elm_genlist_first_item_get(gl),
         ELM_GENLIST_ITEM_NONE, NULL,
         NULL);
      elm_object_item_del(elm_genlist_last_item_get(gl));
   }
   else if (dir == DOWN)
   {
      cerr << __FUNCTION__ << ":" << "Down" << endl;
      elm_object_item_del(elm_genlist_first_item_get(gl));
      elm_genlist_item_append(gl,
         itc1, NULL, NULL, ELM_GENLIST_ITEM_NONE,
         NULL, NULL);
   }
   delete *dci;
}