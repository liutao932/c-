file(REMOVE_RECURSE
  "../../_lib/libworkflow.pdb"
  "../../_lib/libworkflow.so"
  "../../_lib/libworkflow.so.0.10.4"
  "../../_lib/libworkflow.so.0"
)

# Per-language clean rules from dependency scanning.
foreach(lang C CXX)
  include(CMakeFiles/workflow-shared.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
