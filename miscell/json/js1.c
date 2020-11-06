/*  sudo apt-get install json-c-dev
 *  gcc js1.c -ljson-c
 *  https://stackoverflow.com/questions/14879876/how-to-get-json-values-after-json-tokener-parse
 * 
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#include <json-c/json.h> // check /usr/include/jsonc-c, search sub dir inside /usr/include

int main(int argc, char **argv)
{
      json_object *new_obj;
      char buf[] = "{ \"foo\": \"bar\", \"foo2\": \"bar2\", \"foo3\": \"bar3\" }";
      new_obj = json_tokener_parse(buf);

      json_object *obj_foo = json_object_object_get(new_obj,"foo");
      char *foo_val = json_object_get_string(obj_foo);
      printf("value of foo: %s\n", foo_val);
      
      //short way
      printf("The value of foo2:%s\n", json_object_get_string(json_object_object_get(new_obj, "foo2")));


}
