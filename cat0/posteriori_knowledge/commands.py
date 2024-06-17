commands = [
   {
        "ins_index": 0,
        "ins_type": "Compound_ins",
        "ins_num": 4,
        "ops": [
            {
                "op_index": 0,
                "op_name": "symtag1",
                "op_input_byte": "0001",
                "type": "fixed",
            },
            {
                "op_index": 1,
                "op_name": "symtag2",
                "op_input_byte": "n"*22,
                "type": "input",
            },
             {
                "op_index": 2,
                "op_name": "symtag3",
                "op_input_byte": "k"*22,
                "type": "input",
            },{
                "op_index": 3,
                "op_name": "symtag4",
                "op_input_byte": "0010",
                "type": "input",
            }
        ],
        "max_use_num": 10,
    },
    {
        "ins_index": 1,
        "ins_type": "Compound_ins",
        "ins_num": 6,
        "ops": [
            {
                "op_index": 4,
                "op_name": "symtag5",
                "op_input_byte": "0002",
                "type": "fixed",
            },
            {
                "op_index": 5,
                "op_name": "symtag6",
                "op_input_byte": "0000",
                "type": "input",
            },
            {
                "op_index": 6,
                "op_name": "symtag7",
                "op_input_byte": "n"*22,
                "type": "input",
            },
             {
                "op_index": 7,
                "op_name": "symtag8",
                "op_input_byte": "k"*22,
                "type": "input",
            },{
                "op_index": 8,
                "op_name": "symtag9",
                "op_input_byte": "0020",
                "type": "input",
            },{
                "op_index": 9,
                "op_name": "symtag10",
                "op_input_byte": "yyyy",
                "type": "input",
            }
        ],
        "max_use_num": 10,
    },
    {
        "ins_index": 2,
        "ins_type": "Compound_ins",
        "ins_num": 2,
        "ops": [
            {
                "op_index": 10,
                "op_name": "symtag11",
                "op_input_byte": "0005",
                "type": "fixed",
            },
             {
                "op_index": 11,
                "op_name": "symtag12",
                "op_input_byte": "0000",
                "type": "input",
            }
        ],
        "max_use_num": 10,
    }
    
    ]

normal_behavior=[[0,1,2]]
# print(commands)