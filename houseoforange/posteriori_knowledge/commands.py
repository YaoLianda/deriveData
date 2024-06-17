commands = [
    {
    "ins_index":0,
    "ins_type":"Compound_ins",
    "ins_num":5,
    "ops":[
        {"op_index":0,"op_name":"symtag1","op_input_byte":"0"*3+"1"+"0"*11,"type":"fixed"},
        {"op_index":1,"op_name":"symtag2","op_input_byte":"0"*3+"8"+"0"*11,"type":"input"},
         {"op_index":2,"op_name":"symtag3","op_input_byte":"a"*8,"type":"input"},
          {"op_index":3,"op_name":"symtag4","op_input_byte":"0"*2+"18"+"0"*11,"type":"input"}, 
          {"op_index":4,"op_name":"symtag5","op_input_byte":"0"*3+"6"+"0"*11,"type":"input"},
    ],
    "max_use_num":3,
    "depend_index":-1
    },
    {
    "ins_index":1,
    "ins_type":"Compound_ins",
    "ins_num":2,
    "ops":[
        {"op_index":5,"op_name":"symtag6","op_input_byte":"0"*3+"3"+"0"*11,"type":"fixed"},
        {"op_index":6,"op_name":"symtag7","op_input_byte":"0"*3+"8"+"0"*11,"type":"input"},
         {"op_index":7,"op_name":"symtag8","op_input_byte":"b"*8,"type":"input"},
          {"op_index":8,"op_name":"symtag9","op_input_byte":"0"*2+"20"+"0"*11,"type":"input"}, 
          {"op_index":9,"op_name":"symtag10","op_input_byte":"0"*3+"5"+"0"*11,"type":"input"},
    ],
    "max_use_num":3,
    "depend_index":-1
    }
    ]

normal_behavior=[[0,1]]
# print(commands)