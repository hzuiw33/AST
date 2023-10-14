#include <stdio.h>
#include <json-c/json.h>
#include <string.h>

// Function to count if conditions
void count_if_conditions(struct json_object* object, int* if_count) {
    if (json_object_get_type(object) == json_type_object) {
        struct json_object* nodetype_obj;
        if (json_object_object_get_ex(object, "_nodetype", &nodetype_obj)) {
            if (json_object_get_string(nodetype_obj) && strcmp(json_object_get_string(nodetype_obj), "If") == 0) {
                (*if_count)++;
            }

            json_object_object_foreach(object, key, val) {
                count_if_conditions(val, if_count);
            }
        }
    }
    else if (json_object_get_type(object) == json_type_array) {
        int array_len = json_object_array_length(object);
        for (int i = 0; i < array_len; i++) {
            struct json_object* element = json_object_array_get_idx(object, i);
            count_if_conditions(element, if_count);
        }
    }
}

// Function to retrieve the name based on the specified conditions
const char* get_name(struct json_object* function) {
    struct json_object* func_type;
    if (json_object_object_get_ex(function, "type", &func_type)) {
        // Check if "type" has "_nodetype" equal to "FuncDecl"
        struct json_object* _nodetype;
        if (json_object_object_get_ex(func_type, "_nodetype", &_nodetype)) {
            if (json_object_get_type(_nodetype) == json_type_string &&
                strcmp(json_object_get_string(_nodetype), "FuncDecl") == 0) {
                struct json_object* func_name;
                if (json_object_object_get_ex(function, "name", &func_name)) {
                    return json_object_get_string(func_name);
                }
            }
        }
    }
    else {
        // "type" not found, check for "decl" structure
        struct json_object* decl_obj;
        if (json_object_object_get_ex(function, "decl", &decl_obj)) {
            struct json_object* decl_type;
            if (json_object_object_get_ex(decl_obj, "type", &decl_type)) {
                // Check if "decl"->"type" has "_nodetype" equal to "FuncDecl"
                struct json_object* decl_type_nodetype;
                if (json_object_object_get_ex(decl_type, "_nodetype", &decl_type_nodetype)) {
                    if (json_object_get_type(decl_type_nodetype) == json_type_string &&
                        strcmp(json_object_get_string(decl_type_nodetype), "FuncDecl") == 0) {
                        struct json_object* decl_name;
                        if (json_object_object_get_ex(decl_obj, "name", &decl_name)) {
                            return json_object_get_string(decl_name);
                        }
                    }
                }
            }
        }
    }
    return NULL;
}

const char* get_return_type(struct json_object* function) {
    struct json_object* type = NULL;
    struct json_object* decl = NULL;
    struct json_object* type_decl = NULL;
    struct json_object* names = NULL;

    // Traverse deeply to find the return type
    while (json_object_object_get_ex(function, "type", &type)) {
        function = type;  // Move to the next level

        if (json_object_object_get_ex(type, "type", &decl)) {
            type = decl;
        }

        if (json_object_object_get_ex(decl, "type", &type_decl)) {
            type = type_decl;
        }

        if (json_object_object_get_ex(type, "names", &names)) {
            if (json_object_array_length(names) > 0) {
                return json_object_get_string(json_object_array_get_idx(names, 0));
            }
        }
    }

    // When no more exploration is possible, attempt to search through "decl"
    if (json_object_object_get_ex(function, "decl", &decl)) {
        while (json_object_object_get_ex(decl, "type", &type_decl)) {
            decl = type_decl;
            if (json_object_object_get_ex(type_decl, "type", &type_decl)) {
                type_decl = type_decl;
            }
            if (json_object_object_get_ex(type_decl, "names", &names)) {
                if (json_object_array_length(names) > 0) {
                    return json_object_get_string(json_object_array_get_idx(names, 0));
                }
            }
        }
    }

    // When no more exploration is possible, consider that there is no return type
    return "no";
}

// Function to retrieve and print parameter names
void print_param_names(struct json_object* function) {
    struct json_object* params = NULL;
    struct json_object* args = NULL;
    struct json_object* params_list = NULL;

    // 추가: params를 가져오는데 성공했는지 확인
    if (json_object_object_get_ex(function, "type", &params)) {
        // 추가: args를 가져오는데 성공했는지 확인
        if (json_object_object_get_ex(params, "args", &args)) {
            if (json_object_get_type(args) == json_type_object) {
                // 추가: params_list를 가져오는데 성공했는지 확인
                if (json_object_object_get_ex(args, "params", &params_list)) {
                    int array_len = json_object_array_length(params_list);
                    for (int i = 0; i < array_len; i++) {
                        struct json_object* param = json_object_array_get_idx(params_list, i);
                        struct json_object* param_name = NULL;

                        // 추가: param_name을 가져오는데 성공했는지 확인
                        if (json_object_object_get_ex(param, "name", &param_name)) {
                            printf("Parameter %d Name: %s\n", i + 1, json_object_get_string(param_name));
                        }
                    }
                }
            }
        }
    }
    else {
        // Access the "args" inside "decl" if "params" not found
        struct json_object* decl;
        if (json_object_object_get_ex(function, "decl", &decl)) {
            struct json_object* type;
            if (json_object_object_get_ex(decl, "type", &type)) {
                struct json_object* args_decl;
                if (json_object_object_get_ex(type, "args", &args_decl)) {
                    struct json_object* params_list_decl;
                    if (json_object_object_get_ex(args_decl, "params", &params_list_decl)) {
                        int array_len_decl = json_object_array_length(params_list_decl);
                        for (int i = 0; i < array_len_decl; i++) {
                            struct json_object* param_decl = json_object_array_get_idx(params_list_decl, i);
                            struct json_object* param_name_decl;
                            if (json_object_object_get_ex(param_decl, "name", &param_name_decl)) {
                                printf("Parameter %d Name: %s\n", i + 1, json_object_get_string(param_name_decl));
                            }
                        }
                    }
                }
            }
        }
    }
}

// Function to retrieve and print parameter types
void print_param_types(struct json_object* function) {
    struct json_object* params = NULL;
    struct json_object* args = NULL;
    struct json_object* params_list = NULL;
    struct json_object* param_type = NULL;
    struct json_object* type_decl = NULL;
    struct json_object* names = NULL;

    // 추가: params를 가져오는데 성공했는지 확인
    if (json_object_object_get_ex(function, "type", &params)) {
        // 추가: args를 가져오는데 성공했는지 확인
        if (json_object_object_get_ex(params, "args", &args)) {
            if (json_object_get_type(args) == json_type_object) {
                // 추가: params_list를 가져오는데 성공했는지 확인
                if (json_object_object_get_ex(args, "params", &params_list)) {
                    int array_len = json_object_array_length(params_list);
                    for (int i = 0; i < array_len; i++) {
                        struct json_object* param = json_object_array_get_idx(params_list, i);

                        // 추가: param_type을 가져오는데 성공했는지 확인
                        if (json_object_object_get_ex(param, "type", &param_type)) {
                            // 추가: type_decl을 가져오는데 성공했는지 확인
                            if (json_object_object_get_ex(param_type, "type", &type_decl)) {
                                if (json_object_object_get_ex(type_decl, "names", &names)) {
                                    if (json_object_array_length(names) > 0) {
                                        printf("Parameter %d Type: %s\n", i + 1, json_object_get_string(json_object_array_get_idx(names, 0)));
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else {
        // Access the "args" inside "decl" if "params" not found
        struct json_object* decl;
        json_object_object_get_ex(function, "decl", &decl);
        json_object_object_get_ex(decl, "type", &params);

        struct json_object* args_decl;

        if (json_object_object_get_ex(params, "args", &args_decl)) {
            struct json_object* params_list_decl;
            if (json_object_object_get_ex(args_decl, "params", &params_list_decl)) {
                int array_len_decl = json_object_array_length(params_list_decl);
                for (int i = 0; i < array_len_decl; i++) {
                    struct json_object* param_decl = json_object_array_get_idx(params_list_decl, i);
                    struct json_object* param_type_decl;
                    if (json_object_object_get_ex(param_decl, "type", &param_type_decl)) {
                        struct json_object* names_decl;
                        if (json_object_object_get_ex(param_type_decl, "type", &param_type_decl)) {
                            if (json_object_object_get_ex(param_type_decl, "names", &names_decl)) {
                                if (json_object_array_length(names_decl) > 0) {
                                    printf("Parameter %d Type: %s\n", i + 1, json_object_get_string(json_object_array_get_idx(names_decl, 0)));
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

// Function to retrieve and print function information
void process_function(struct json_object* function) {
    struct json_object* params;
    json_object_object_get_ex(function, "type", &params);

    int if_count = 0;
    count_if_conditions(function, &if_count);

    printf("Function Name: %s\n", get_name(function));
    printf("Return Type: %s\n", get_return_type(function));
    printf("Number of If Conditions: %d\n", if_count);
    print_param_names(function);
    print_param_types(function);

    printf("\n");
}

// Function to process functions from a JSON object
// Function to process functions from a JSON object
void process_functions_from_json(struct json_object* ext) {
    int array_len = json_object_array_length(ext);
    int function_count = 0;

    for (int i = 0; i < array_len; i++) {
        struct json_object* function = json_object_array_get_idx(ext, i);
        // Check if "type" has "_nodetype" equal to "FuncDecl"
        struct json_object* func_type;
        if (json_object_object_get_ex(function, "type", &func_type)) {
            struct json_object* _nodetype;
            if (json_object_object_get_ex(func_type, "_nodetype", &_nodetype)) {
                if (json_object_get_type(_nodetype) == json_type_string &&
                    strcmp(json_object_get_string(_nodetype), "FuncDecl") == 0) {
                    function_count++;
                }
            }
        }
        else {
            // "type" not found, check for "decl" structure
            struct json_object* decl_obj;
            if (json_object_object_get_ex(function, "decl", &decl_obj)) {
                struct json_object* decl_type;
                if (json_object_object_get_ex(decl_obj, "type", &decl_type)) {
                    // Check if "decl"->"type" has "_nodetype" equal to "FuncDecl"
                    struct json_object* decl_type_nodetype;
                    if (json_object_object_get_ex(decl_type, "_nodetype", &decl_type_nodetype)) {
                        if (json_object_get_type(decl_type_nodetype) == json_type_string &&
                            strcmp(json_object_get_string(decl_type_nodetype), "FuncDecl") == 0) {
                            function_count++;
                        }
                    }
                }
            }
        }
    }

    // Total Number of Functions print
    printf("Total Number of Functions: %d\n\n", function_count);

    for (int i = 0; i < array_len; i++) {
        struct json_object* function = json_object_array_get_idx(ext, i);
        // Check if "type" has "_nodetype" equal to "FuncDecl"
        struct json_object* func_type;
        if (json_object_object_get_ex(function, "type", &func_type)) {
            struct json_object* _nodetype;
            if (json_object_object_get_ex(func_type, "_nodetype", &_nodetype)) {
                if (json_object_get_type(_nodetype) == json_type_string &&
                    strcmp(json_object_get_string(_nodetype), "FuncDecl") == 0) {
                    process_function(function);
                }
            }
        }
        else {
            // "type" not found, check for "decl" structure
            struct json_object* decl_obj;
            if (json_object_object_get_ex(function, "decl", &decl_obj)) {
                struct json_object* decl_type;
                if (json_object_object_get_ex(decl_obj, "type", &decl_type)) {
                    // Check if "decl"->"type" has "_nodetype" equal to "FuncDecl"
                    struct json_object* decl_type_nodetype;
                    if (json_object_object_get_ex(decl_type, "_nodetype", &decl_type_nodetype)) {
                        if (json_object_get_type(decl_type_nodetype) == json_type_string &&
                            strcmp(json_object_get_string(decl_type_nodetype), "FuncDecl") == 0) {
                            process_function(function);
                        }
                    }
                }
            }
        }
    }
}



int main() {
    FILE* file = fopen("data.json", "r");
    if (!file) {
        fprintf(stderr, "Failed to open file.\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* file_content = (char*)malloc(file_size * sizeof(char));
    fread(file_content, sizeof(char), file_size, file);
    fclose(file);

    struct json_object* json = json_tokener_parse(file_content);
    free(file_content);

    struct json_object* ext = json_object_object_get(json, "ext");


    process_functions_from_json(ext);


    json_object_put(json);
    return 0;
}
