#include <iostream>

#include "gcc-plugin.h"
#include "plugin-version.h"

#include "tree-pass.h"
#include "context.h"
#include "basic-block.h"
#include "gimple-pretty-print.h"
#include "tree.h"
#include "print-tree.h"
#include "gimple.h"
#include "gimple-iterator.h"
#include "gimple-expr.h"

// We must assert that this plugin is GPL compatible
int plugin_is_GPL_compatible;

// TODO: proper description
static struct plugin_info my_plugin_info = {
    .version = "1.0", 
    .help = "TBD"
};


struct pass_data my_pass_data = {
		.type = GIMPLE_PASS,
		.name = "ssa_pass",						/* name */
		.optinfo_flags = OPTGROUP_NONE,			/* optinfo_flags */
		.tv_id = TV_NONE,						/* tv_id */
		.properties_required = PROP_gimple_any,	/* properties_required */
		.properties_provided = 0,				/* properties_provided */
		.properties_destroyed = 0,				/* properties_destroyed */
		.todo_flags_start = 0,					/* todo_flags_start */
		.todo_flags_finish = 0					/* todo_flags_finish */
	};

class my_ssa_pass : public gimple_opt_pass {
    public: 
        my_ssa_pass (const pass_data& data, gcc::context *ctxt) : gimple_opt_pass (data, ctxt) {}

        /**
         * Execute pass if gate returns true
         */ 
        bool gate (function* gate_fun) {
            return true;
        }

        /**
         * Code to run when a pass is executed
         */
        unsigned int execute(function *func) {
            basic_block bb;
            FOR_ALL_BB_FN(bb, func) {
                gimple_bb_info *bb_info = &bb->il.gimple;
                // Entry block
                if (bb->index == 0) {
                    
                }
                // Exit block
                else if (bb->index == 1) {
                }
                // Other blocks
                else {
                }
            }
            return 0;
        }
};

// Plugin initialization
int plugin_init(struct plugin_name_args *plugin_info, struct plugin_gcc_version *version) {
	// Check plugin version against gcc version
	if (!plugin_default_version_check(version, &gcc_version)) {
		std::cerr << "This GCC plugin is for version " << GCCPLUGIN_VERSION_MAJOR
			<< "." << GCCPLUGIN_VERSION_MINOR << "\n";
	    return 1;
    }

	register_callback(plugin_info->base_name, PLUGIN_INFO, NULL, &my_plugin_info);

    // Register the phase right after ssa
    struct register_pass_info pass_info;

    pass_info.pass = new my_ssa_pass(my_pass_data, g);
    pass_info.reference_pass_name = "ssa";
	pass_info.ref_pass_instance_number = 1;
    pass_info.pos_op = PASS_POS_INSERT_AFTER;
	register_callback(plugin_info->base_name, PLUGIN_PASS_MANAGER_SETUP, NULL, &pass_info);
	// pass after we finish, probably will be used for printing final JSON
	//register_callback(plugin_info->base_name, PLUGIN_ATTRIBUTES, register_attributes, NULL);
	return 0;
}