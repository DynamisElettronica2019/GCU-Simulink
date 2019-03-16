function ss2sf(mdl,subsystemNames)
% Function to create s-functions out of sub-systems supplied.
%mdl - name of the model (string)
%subsystemNames - Sub-System paths (cell array)
%
%ssnames{1}='f14/Controller';
%ssnames{2}='f14/Aircraft Dynamics Model';
%ss2sf('f14',ssnames)

load_system(mdl)

for idx=1:length(subsystemNames)
    pos=get_param(subsystemNames{idx},'position')

    new_system('mysys','Model',subsystemNames{idx})
    delete_block(subsystemNames{idx})

    set_param('mysys','RTWSystemTargetFile','rtwsfcn.tlc')
    set_param('mysys','RTWTemplateMakefile','rtwsfcn_default_tmf')
    rtwbuild('mysys');
    open_system(mdl);
    add_block('untitled/RTW S-Function',subsystemNames{idx},'position',pos);
    bdclose untitled;
    bdclose mysys;
    clear pos;
end

