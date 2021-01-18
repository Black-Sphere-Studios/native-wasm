// Copyright (c)2021 Fundament Software
// For conditions of distribution and use, see copyright notice in innative.h

#include "constants.h"
#include "innative/schema.h"

__KHASH_IMPL(mapenum, , int, const char*, 1, kh_int_hash_func, kh_int_hash_equal);

const innative::utility::OP innative::utility::OP::NAMES;

innative::utility::OP::OP() : MAP(kh_init_mapenum())
{
  int r;
  for(auto& e : LIST)
  {
    auto iter         = kh_put_mapenum(MAP, ToInt(e.first), &r);
    kh_val(MAP, iter) = e.second;
  }
}
innative::utility::OP::~OP() { kh_destroy_mapenum(MAP); }

const char* innative::utility::OP::Get(int code) const
{
  khiter_t iter = kh_get_mapenum(MAP, code);
  if(kh_exist2(MAP, iter))
    return kh_val(MAP, iter);
  return nullptr;
}

namespace innative {
  namespace utility {
    kh_mapenum_s* GenMapEnum(std::initializer_list<std::pair<int, const char*>> list)
    {
      auto h = kh_init_mapenum();
      int r;

      for(auto& e : list)
      {
        auto iter       = kh_put_mapenum(h, e.first, &r);
        kh_val(h, iter) = e.second;
      }

      return h;
    }

    const kh_mapenum_s* ERR_ENUM_MAP = GenMapEnum({
      { ERR_SUCCESS, "ERR_SUCCESS" },
      { ERR_PARSE_UNEXPECTED_EOF, "ERR_PARSE_UNEXPECTED_EOF" },
      { ERR_PARSE_INVALID_MAGIC_COOKIE, "ERR_PARSE_INVALID_MAGIC_COOKIE" },
      { ERR_PARSE_INVALID_VERSION, "ERR_PARSE_INVALID_VERSION" },
      { ERR_PARSE_INVALID_FILE_LENGTH, "ERR_PARSE_INVALID_FILE_LENGTH" },
      { ERR_PARSE_INVALID_NAME, "ERR_PARSE_INVALID_NAME" },
      { ERR_UNKNOWN_COMMAND_LINE, "ERR_UNKNOWN_COMMAND_LINE" },
      { ERR_MISSING_COMMAND_LINE_PARAMETER, "ERR_MISSING_COMMAND_LINE_PARAMETER" },
      { ERR_INVALID_COMMAND_LINE, "ERR_INVALID_COMMAND_LINE" },
      { ERR_NO_INPUT_FILES, "ERR_NO_INPUT_FILES" },
      { ERR_UNKNOWN_ENVIRONMENT_ERROR, "ERR_UNKNOWN_ENVIRONMENT_ERROR" },
      { ERR_COMMAND_LINE_CONFLICT, "ERR_COMMAND_LINE_CONFLICT" },
      { ERR_UNKNOWN_FLAG, "ERR_UNKNOWN_FLAG" },
      { ERR_MISSING_LOADER, "ERR_MISSING_LOADER" },
      { ERR_INSUFFICIENT_BUFFER, "ERR_INSUFFICIENT_BUFFER" },
      { ERR_FATAL_INVALID_WASM_SECTION_ORDER, "ERR_FATAL_INVALID_WASM_SECTION_ORDER" },
      { ERR_FATAL_INVALID_MODULE, "ERR_FATAL_INVALID_MODULE" },
      { ERR_FATAL_INVALID_LLVM_IR, "ERR_FATAL_INVALID_LLVM_IR" },
      { ERR_FATAL_INVALID_ENCODING, "ERR_FATAL_INVALID_ENCODING" },
      { ERR_FATAL_OVERLONG_ENCODING, "ERR_FATAL_OVERLONG_ENCODING" },
      { ERR_FATAL_UNKNOWN_KIND, "ERR_FATAL_UNKNOWN_KIND" },
      { ERR_FATAL_UNKNOWN_INSTRUCTION, "ERR_FATAL_UNKNOWN_INSTRUCTION" },
      { ERR_FATAL_UNKNOWN_SECTION, "ERR_FATAL_UNKNOWN_SECTION" },
      { ERR_FATAL_SECTION_SIZE_MISMATCH, "ERR_FATAL_SECTION_SIZE_MISMATCH" },
      { ERR_FATAL_FUNCTION_SIZE_MISMATCH, "ERR_FATAL_FUNCTION_SIZE_MISMATCH" },
      { ERR_FATAL_UNKNOWN_FUNCTION_SIGNATURE, "ERR_FATAL_UNKNOWN_FUNCTION_SIGNATURE" },
      { ERR_FATAL_UNKNOWN_TARGET, "ERR_FATAL_UNKNOWN_TARGET" },
      { ERR_FATAL_EXPECTED_END_INSTRUCTION, "ERR_FATAL_EXPECTED_END_INSTRUCTION" },
      { ERR_FATAL_NULL_POINTER, "ERR_FATAL_NULL_POINTER" },
      { ERR_FATAL_BAD_ELEMENT_TYPE, "ERR_FATAL_BAD_ELEMENT_TYPE" },
      { ERR_FATAL_BAD_HASH, "ERR_FATAL_BAD_HASH" },
      { ERR_FATAL_DUPLICATE_EXPORT, "ERR_FATAL_DUPLICATE_EXPORT" },
      { ERR_FATAL_DUPLICATE_MODULE_NAME, "ERR_FATAL_DUPLICATE_MODULE_NAME" },
      { ERR_FATAL_FILE_ERROR, "ERR_FATAL_FILE_ERROR" },
      { ERR_FATAL_DEBUG_ERROR, "ERR_FATAL_DEBUG_ERROR" },
      { ERR_FATAL_DEBUG_OBJ_ERROR, "ERR_FATAL_DEBUG_OBJ_ERROR" },
      { ERR_FATAL_FORMAT_ERROR, "ERR_FATAL_FORMAT_ERROR" },
      { ERR_FATAL_LINK_ERROR, "ERR_FATAL_LINK_ERROR" },
      { ERR_FATAL_TOO_MANY_LOCALS, "ERR_FATAL_TOO_MANY_LOCALS" },
      { ERR_FATAL_OUT_OF_MEMORY, "ERR_FATAL_OUT_OF_MEMORY" },
      { ERR_FATAL_RESOURCE_ERROR, "ERR_FATAL_RESOURCE_ERROR" },
      { ERR_FATAL_NO_OUTPUT_FILE, "ERR_FATAL_NO_OUTPUT_FILE" },
      { ERR_FATAL_NO_MODULES, "ERR_FATAL_NO_MODULES" },
      { ERR_FATAL_NO_START_FUNCTION, "ERR_FATAL_NO_START_FUNCTION" },
      { ERR_FATAL_MULTIPLE_START_SECTIONS, "ERR_FATAL_MULTIPLE_START_SECTIONS" },
      { ERR_FATAL_DATA_COUNT_MISMATCH, "ERR_FATAL_DATA_COUNT_MISMATCH" },
      { ERR_VALIDATION_ERROR, "ERR_VALIDATION_ERROR" },
      { ERR_INVALID_FUNCTION_SIG, "ERR_INVALID_FUNCTION_SIG" },
      { ERR_INVALID_FUNCTION_INDEX, "ERR_INVALID_FUNCTION_INDEX" },
      { ERR_INVALID_TABLE_INDEX, "ERR_INVALID_TABLE_INDEX" },
      { ERR_INVALID_MEMORY_INDEX, "ERR_INVALID_MEMORY_INDEX" },
      { ERR_INVALID_GLOBAL_INDEX, "ERR_INVALID_GLOBAL_INDEX" },
      { ERR_INVALID_DATA_INDEX, "ERR_INVALID_DATA_INDEX" },
      { ERR_INVALID_ELEMENT_INDEX, "ERR_INVALID_ELEMENT_INDEX" },
      { ERR_INVALID_IMPORT_MEMORY_MINIMUM, "ERR_INVALID_IMPORT_MEMORY_MINIMUM" },
      { ERR_INVALID_IMPORT_MEMORY_MAXIMUM, "ERR_INVALID_IMPORT_MEMORY_MAXIMUM" },
      { ERR_INVALID_IMPORT_TABLE_MINIMUM, "ERR_INVALID_IMPORT_TABLE_MINIMUM" },
      { ERR_INVALID_IMPORT_TABLE_MAXIMUM, "ERR_INVALID_IMPORT_TABLE_MAXIMUM" },
      { ERR_INVALID_IDENTIFIER, "ERR_INVALID_IDENTIFIER" },
      { ERR_INVALID_TABLE_ELEMENT_TYPE, "ERR_INVALID_TABLE_ELEMENT_TYPE" },
      { ERR_INVALID_LIMITS, "ERR_INVALID_LIMITS" },
      { ERR_INVALID_INITIALIZER, "ERR_INVALID_INITIALIZER" },
      { ERR_INVALID_GLOBAL_INITIALIZER, "ERR_INVALID_GLOBAL_INITIALIZER" },
      { ERR_INVALID_INITIALIZER_TYPE, "ERR_INVALID_INITIALIZER_TYPE" },
      { ERR_INVALID_GLOBAL_TYPE, "ERR_INVALID_GLOBAL_TYPE" },
      { ERR_INVALID_GLOBAL_IMPORT_TYPE, "ERR_INVALID_GLOBAL_IMPORT_TYPE" },
      { ERR_INVALID_TABLE_TYPE, "ERR_INVALID_TABLE_TYPE" },
      { ERR_INVALID_MEMORY_TYPE, "ERR_INVALID_MEMORY_TYPE" },
      { ERR_INVALID_START_FUNCTION, "ERR_INVALID_START_FUNCTION" },
      { ERR_INVALID_TABLE_OFFSET, "ERR_INVALID_TABLE_OFFSET" },
      { ERR_INVALID_MEMORY_OFFSET, "ERR_INVALID_MEMORY_OFFSET" },
      { ERR_INVALID_FUNCTION_BODY, "ERR_INVALID_FUNCTION_BODY" },
      { ERR_INVALID_FUNCTION_IMPORT_TYPE, "ERR_INVALID_FUNCTION_IMPORT_TYPE" },
      { ERR_INVALID_VALUE_STACK, "ERR_INVALID_VALUE_STACK" },
      { ERR_EMPTY_VALUE_STACK, "ERR_EMPTY_VALUE_STACK" },
      { ERR_INVALID_TYPE, "ERR_INVALID_TYPE" },
      { ERR_INVALID_TYPE_INDEX, "ERR_INVALID_TYPE_INDEX" },
      { ERR_INVALID_BRANCH_DEPTH, "ERR_INVALID_BRANCH_DEPTH" },
      { ERR_INVALID_LOCAL_INDEX, "ERR_INVALID_LOCAL_INDEX" },
      { ERR_INVALID_ARGUMENT_TYPE, "ERR_INVALID_ARGUMENT_TYPE" },
      { ERR_INVALID_BLOCK_SIGNATURE, "ERR_INVALID_BLOCK_SIGNATURE" },
      { ERR_INVALID_MEMORY_ALIGNMENT, "ERR_INVALID_MEMORY_ALIGNMENT" },
      { ERR_INVALID_RESERVED_VALUE, "ERR_INVALID_RESERVED_VALUE" },
      { ERR_INVALID_UTF8_ENCODING, "ERR_INVALID_UTF8_ENCODING" },
      { ERR_INVALID_DATA_SEGMENT, "ERR_INVALID_DATA_SEGMENT" },
      { ERR_INVALID_ELEMENT_SEGMENT, "ERR_INVALID_ELEMENT_SEGMENT" },
      { ERR_INVALID_MUTABILITY, "ERR_INVALID_MUTABILITY" },
      { ERR_INVALID_EMBEDDING, "ERR_INVALID_EMBEDDING" },
      { ERR_IMMUTABLE_GLOBAL, "ERR_IMMUTABLE_GLOBAL" },
      { ERR_UNKNOWN_SIGNATURE_TYPE, "ERR_UNKNOWN_SIGNATURE_TYPE" },
      { ERR_UNKNOWN_MODULE, "ERR_UNKNOWN_MODULE" },
      { ERR_UNKNOWN_EXPORT, "ERR_UNKNOWN_EXPORT" },
      { ERR_UNKNOWN_BLANK_IMPORT, "ERR_UNKNOWN_BLANK_IMPORT" },
      { ERR_EMPTY_IMPORT, "ERR_EMPTY_IMPORT" },
      { ERR_MULTIPLE_RETURN_VALUES, "ERR_MULTIPLE_RETURN_VALUES" },
      { ERR_MULTIPLE_TABLES, "ERR_MULTIPLE_TABLES" },
      { ERR_MULTIPLE_MEMORIES, "ERR_MULTIPLE_MEMORIES" },
      { ERR_IMPORT_EXPORT_MISMATCH, "ERR_IMPORT_EXPORT_MISMATCH" },
      { ERR_IMPORT_EXPORT_TYPE_MISMATCH, "ERR_IMPORT_EXPORT_TYPE_MISMATCH" },
      { ERR_FUNCTION_BODY_MISMATCH, "ERR_FUNCTION_BODY_MISMATCH" },
      { ERR_MEMORY_MINIMUM_TOO_LARGE, "ERR_MEMORY_MINIMUM_TOO_LARGE" },
      { ERR_MEMORY_MAXIMUM_TOO_LARGE, "ERR_MEMORY_MAXIMUM_TOO_LARGE" },
      { ERR_SHARED_MEMORY_MAXIMUM_MISSING, "ERR_SHARED_MEMORY_MAXIMUM_MISSING" },
      { ERR_SHARED_MEMORY_MISMATCH, "ERR_SHARED_MEMORY_MISMATCH" },
      { ERR_IF_ELSE_MISMATCH, "ERR_IF_ELSE_MISMATCH" },
      { ERR_END_MISMATCH, "ERR_END_MISMATCH" },
      { ERR_SIGNATURE_MISMATCH, "ERR_SIGNATURE_MISMATCH" },
      { ERR_EXPECTED_ELSE_INSTRUCTION, "ERR_EXPECTED_ELSE_INSTRUCTION" },
      { ERR_ILLEGAL_C_IMPORT, "ERR_ILLEGAL_C_IMPORT" },
      { ERR_JIT_COMPILE_FAILURE, "ERR_JIT_COMPILE_FAILURE" },
      { ERR_JIT_TARGET_MACHINE_FAILURE, "ERR_JIT_TARGET_MACHINE_FAILURE" },
      { ERR_JIT_DATA_LAYOUT_ERROR, "ERR_JIT_DATA_LAYOUT_ERROR" },
      { ERR_JIT_LINK_PROCESS_FAILURE, "ERR_JIT_LINK_PROCESS_FAILURE" },
      { ERR_JIT_LINK_FAILURE, "ERR_JIT_LINK_FAILURE" },
      { ERR_MISSING_DATA_COUNT_SECTION, "ERR_MISSING_DATA_COUNT_SECTION" },
      { ERR_WAT_INTERNAL_ERROR, "ERR_WAT_INTERNAL_ERROR" },
      { ERR_WAT_EXPECTED_OPEN, "ERR_WAT_EXPECTED_OPEN" },
      { ERR_WAT_EXPECTED_CLOSE, "ERR_WAT_EXPECTED_CLOSE" },
      { ERR_WAT_EXPECTED_TOKEN, "ERR_WAT_EXPECTED_TOKEN" },
      { ERR_WAT_EXPECTED_NAME, "ERR_WAT_EXPECTED_NAME" },
      { ERR_WAT_EXPECTED_STRING, "ERR_WAT_EXPECTED_STRING" },
      { ERR_WAT_EXPECTED_VALUE, "ERR_WAT_EXPECTED_VALUE" },
      { ERR_WAT_EXPECTED_NUMBER, "ERR_WAT_EXPECTED_NUMBER" },
      { ERR_WAT_EXPECTED_TYPE, "ERR_WAT_EXPECTED_TYPE" },
      { ERR_WAT_EXPECTED_VAR, "ERR_WAT_EXPECTED_VAR" },
      { ERR_WAT_EXPECTED_VALTYPE, "ERR_WAT_EXPECTED_VALTYPE" },
      { ERR_WAT_EXPECTED_FUNC, "ERR_WAT_EXPECTED_FUNC" },
      { ERR_WAT_EXPECTED_OPERATOR, "ERR_WAT_EXPECTED_OPERATOR" },
      { ERR_WAT_EXPECTED_INTEGER, "ERR_WAT_EXPECTED_INTEGER" },
      { ERR_WAT_EXPECTED_FLOAT, "ERR_WAT_EXPECTED_FLOAT" },
      { ERR_WAT_EXPECTED_RESULT, "ERR_WAT_EXPECTED_RESULT" },
      { ERR_WAT_EXPECTED_THEN, "ERR_WAT_EXPECTED_THEN" },
      { ERR_WAT_EXPECTED_ELSE, "ERR_WAT_EXPECTED_ELSE" },
      { ERR_WAT_EXPECTED_END, "ERR_WAT_EXPECTED_END" },
      { ERR_WAT_EXPECTED_LOCAL, "ERR_WAT_EXPECTED_LOCAL" },
      { ERR_WAT_EXPECTED_FUNCREF, "ERR_WAT_EXPECTED_FUNCREF" },
      { ERR_WAT_EXPECTED_MUT, "ERR_WAT_EXPECTED_MUT" },
      { ERR_WAT_EXPECTED_MODULE, "ERR_WAT_EXPECTED_MODULE" },
      { ERR_WAT_EXPECTED_ELEM, "ERR_WAT_EXPECTED_ELEM" },
      { ERR_WAT_EXPECTED_KIND, "ERR_WAT_EXPECTED_KIND" },
      { ERR_WAT_EXPECTED_EXPORT, "ERR_WAT_EXPECTED_EXPORT" },
      { ERR_WAT_EXPECTED_IMPORT, "ERR_WAT_EXPECTED_IMPORT" },
      { ERR_WAT_EXPECTED_BINARY, "ERR_WAT_EXPECTED_BINARY" },
      { ERR_WAT_EXPECTED_QUOTE, "ERR_WAT_EXPECTED_QUOTE" },
      { ERR_WAT_INVALID_TOKEN, "ERR_WAT_INVALID_TOKEN" },
      { ERR_WAT_INVALID_NUMBER, "ERR_WAT_INVALID_NUMBER" },
      { ERR_WAT_INVALID_IMPORT_ORDER, "ERR_WAT_INVALID_IMPORT_ORDER" },
      { ERR_WAT_INVALID_ALIGNMENT, "ERR_WAT_INVALID_ALIGNMENT" },
      { ERR_WAT_INVALID_NAME, "ERR_WAT_INVALID_NAME" },
      { ERR_WAT_INVALID_VAR, "ERR_WAT_INVALID_VAR" },
      { ERR_WAT_INVALID_TYPE, "ERR_WAT_INVALID_TYPE" },
      { ERR_WAT_INVALID_LOCAL, "ERR_WAT_INVALID_LOCAL" },
      { ERR_WAT_INVALID_MEMORY, "ERR_WAT_INVALID_MEMORY" },
      { ERR_WAT_UNKNOWN_TYPE, "ERR_WAT_UNKNOWN_TYPE" },
      { ERR_WAT_UNEXPECTED_NAME, "ERR_WAT_UNEXPECTED_NAME" },
      { ERR_WAT_TYPE_MISMATCH, "ERR_WAT_TYPE_MISMATCH" },
      { ERR_WAT_LABEL_MISMATCH, "ERR_WAT_LABEL_MISMATCH" },
      { ERR_WAT_OUT_OF_RANGE, "ERR_WAT_OUT_OF_RANGE" },
      { ERR_WAT_BAD_ESCAPE, "ERR_WAT_BAD_ESCAPE" },
      { ERR_WAT_DUPLICATE_NAME, "ERR_WAT_DUPLICATE_NAME" },
      { ERR_WAT_PARAM_AFTER_RESULT, "ERR_WAT_PARAM_AFTER_RESULT" },
      { ERR_RUNTIME_INIT_ERROR, "ERR_RUNTIME_INIT_ERROR" },
      { ERR_RUNTIME_TRAP, "ERR_RUNTIME_TRAP" },
      { ERR_RUNTIME_ASSERT_FAILURE, "ERR_RUNTIME_ASSERT_FAILURE" },
      { ERR_RUNTIME_JIT_ERROR, "ERR_RUNTIME_JIT_ERROR", },
      { ERR_RUNTIME_INVALID_ASSEMBLY, "ERR_RUNTIME_INVALID_ASSEMBLY" },
    });

    const kh_mapenum_s* TYPE_ENCODING_MAP = GenMapEnum({
      { TE_i32, "TE_i32" },
      { TE_i64, "TE_i64" },
      { TE_f32, "TE_f32" },
      { TE_f64, "TE_f64" },
      { TE_funcref, "TE_funcref" },
      { TE_cref, "TE_cref" },
      { TE_func, "TE_func" },
      { TE_void, "TE_void" },
      { TE_iPTR, "TE_iPTR" },
      { TE_NONE, "TE_NONE" },
      { TE_UNKNOWN, "TE_UNKNOWN" },
    });

    const kh_mapenum_s* WAST_ASSERTION_MAP = GenMapEnum({
      { ERR_WAT_INVALID_ALIGNMENT, "alignment" },
      { ERR_INVALID_MEMORY_ALIGNMENT, "alignment must not be larger than natural" },
      { ERR_INVALID_MEMORY_OFFSET, "out of bounds memory access" },
      { ERR_END_MISMATCH, "unexpected end" },
      { ERR_PARSE_INVALID_MAGIC_COOKIE, "magic header not detected" },
      { ERR_PARSE_INVALID_VERSION, "unknown binary version" },
      { ERR_FATAL_OVERLONG_ENCODING, "integer representation too long" },
      { ERR_FATAL_INVALID_ENCODING, "integer too large" },
      { ERR_INVALID_RESERVED_VALUE, "zero flag expected" },
      { ERR_FATAL_TOO_MANY_LOCALS, "too many locals" },
      { ERR_IMPORT_EXPORT_MISMATCH, "type mismatch" },
      { ERR_INVALID_BLOCK_SIGNATURE, "type mismatch" },
      { ERR_EMPTY_VALUE_STACK, "type mismatch" },
      { ERR_INVALID_VALUE_STACK, "type mismatch" },
      { ERR_INVALID_TYPE, "type mismatch" },
      { ERR_WAT_TYPE_MISMATCH, "inline function type" },
      { ERR_WAT_UNKNOWN_TYPE, "unknown type" },
      { ERR_WAT_LABEL_MISMATCH, "mismatching label" },
      { ERR_INVALID_BRANCH_DEPTH, "unknown label" },
      { ERR_INVALID_FUNCTION_INDEX, "unknown function" },
      { ERR_INVALID_TABLE_INDEX, "unknown table" },
      { ERR_WAT_OUT_OF_RANGE, "constant out of range" },
      { ERR_PARSE_UNEXPECTED_EOF, "unexpected end" },
      { ERR_WAT_EXPECTED_OPEN, "unexpected token" },
      { ERR_WAT_EXPECTED_OPERATOR, "unexpected token" },
      { ERR_WAT_UNEXPECTED_NAME, "unexpected token" },
      { ERR_PARSE_INVALID_FILE_LENGTH, "unexpected end" },
      { ERR_FATAL_UNKNOWN_SECTION, "malformed section id" },
      { ERR_FATAL_SECTION_SIZE_MISMATCH, "section size mismatch" },
      { ERR_FUNCTION_BODY_MISMATCH, "function and code section have inconsistent lengths" },
      { ERR_FATAL_DUPLICATE_EXPORT, "duplicate export name" },
      { ERR_INVALID_MEMORY_INDEX, "unknown memory" },
      { ERR_INVALID_GLOBAL_INDEX, "unknown global" },
      { ERR_INVALID_TABLE_INDEX, "unknown table" },
      { ERR_WAT_INVALID_NUMBER, "unknown operator" },
      { ERR_WAT_INVALID_TOKEN, "unknown operator" },
      { ERR_INVALID_GLOBAL_INITIALIZER, "unknown global" },
      { ERR_INVALID_INITIALIZER_TYPE, "type mismatch" },
      { ERR_INVALID_GLOBAL_TYPE, "type mismatch" },
      { ERR_INVALID_TABLE_TYPE, "type mismatch" },
      { ERR_INVALID_LOCAL_INDEX, "unknown local" },
      { ERR_MULTIPLE_RETURN_VALUES, "invalid result arity" },
      { ERR_INVALID_START_FUNCTION, "start function" },
      { ERR_WAT_EXPECTED_VAR, "unknown operator" },
      { ERR_WAT_EXPECTED_VALTYPE, "unexpected token" },
      { ERR_INVALID_UTF8_ENCODING, "malformed UTF-8 encoding" },
      { ERR_INVALID_DATA_SEGMENT, "data segment does not fit" },
      { ERR_INVALID_TABLE_OFFSET, "elements segment does not fit" },
      { ERR_IMMUTABLE_GLOBAL, "global is immutable" },
      { ERR_INVALID_MUTABILITY, "malformed mutability" },
      { ERR_UNKNOWN_EXPORT, "unknown import" },
      { ERR_INVALID_GLOBAL_IMPORT_TYPE, "incompatible import type" },
      { ERR_INVALID_FUNCTION_IMPORT_TYPE, "incompatible import type" },
      { ERR_WAT_INVALID_IMPORT_ORDER, "invalid import order" },
      { ERR_INVALID_IMPORT_MEMORY_MINIMUM, "incompatible import type" },
      { ERR_INVALID_IMPORT_MEMORY_MAXIMUM, "incompatible import type" },
      { ERR_INVALID_IMPORT_TABLE_MINIMUM, "incompatible import type" },
      { ERR_INVALID_IMPORT_TABLE_MAXIMUM, "incompatible import type" },
      { ERR_MULTIPLE_TABLES, "multiple tables" },
      { ERR_MULTIPLE_MEMORIES, "multiple memories" },
      { ERR_IMPORT_EXPORT_TYPE_MISMATCH, "incompatible import type" },
      { ERR_UNKNOWN_MODULE, "unknown import" },
      { ERR_INVALID_LIMITS, "size minimum must not be greater than maximum" },
      { ERR_MEMORY_MAXIMUM_TOO_LARGE, "memory size must be at most 65536 pages (4GiB)" },
      { ERR_MEMORY_MINIMUM_TOO_LARGE, "memory size must be at most 65536 pages (4GiB)" },
      { ERR_SHARED_MEMORY_MAXIMUM_MISSING, "shared memory must have maximum" },
      { ERR_INVALID_INITIALIZER, "constant expression required" },
      { ERR_EMPTY_IMPORT, "unknown import" },
      { ERR_WAT_PARAM_AFTER_RESULT, "unexpected token" },
      { ERR_FATAL_MULTIPLE_START_SECTIONS, "multiple start sections" },
      { ERR_FATAL_INVALID_WASM_SECTION_ORDER, "section size mismatch" },
      { ERR_FATAL_EXPECTED_END_INSTRUCTION, "invalid value type" },
      { ERR_SHARED_MEMORY_MISMATCH, "incompatible import type" },
      { ERR_INVALID_DATA_INDEX, "unknown data segment" },
      { ERR_MISSING_DATA_COUNT_SECTION, "data count section required" },
      { ERR_INVALID_MEMORY_TYPE, "type mismatch" },
      { ERR_WAT_DUPLICATE_NAME, "duplicate name" },
      { ERR_FATAL_DATA_COUNT_MISMATCH, "data count and data section have inconsistent lengths" },
      { ERR_INVALID_ELEMENT_SEGMENT, "invalid elem" },
      { ERR_FATAL_BAD_ELEMENT_TYPE, "malformed element type" },
      { ERR_INVALID_ELEMENT_INDEX, "unknown elem segment" },
    });

    const char* EnumToString(const kh_mapenum_s* h, int i, char* buf, size_t n)
    {
      khiter_t iter = kh_get_mapenum(h, i);
      if(kh_exist2(h, iter))
        return kh_val(h, iter);
      if(!buf)
        return nullptr;
      snprintf(buf, n, "%i", i);
      buf[n - 1] = 0;
      return buf;
    }
  }
}
