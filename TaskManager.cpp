#ifndef _STRING_
#define _STRING_
#include <yvals_core.h>
#if _STL_COMPILER_PREPROCESSOR
#include <xstring>
#include <cctype>

#pragma pack(push, _CRT_PACKING)
#pragma warning(push, _STL_WARNING_LEVEL)
#pragma warning(disable : _STL_DISABLED_WARNINGS)
_STL_DISABLE_CLANG_WARNINGS
#pragma push_macro("new")
#undef new

_STD_BEGIN
_EXPORT_STD template <class _Elem, class _Traits, class _Alloc>
basic_istream<_Elem, _Traits>& getline(
    basic_istream<_Elem, _Traits>&& _Istr, basic_string<_Elem, _Traits, _Alloc>& _Str, const _Elem _Delim) {
    using _Myis = basic_istream<_Elem, _Traits>;

    typename _Myis::iostate _State = _Myis::goodbit;
    bool _Changed                  = false;
    const typename _Myis::sentry _Ok(_Istr, true);

    if (_Ok) { 
        _TRY_IO_BEGIN
        _Str.erase();
        const typename _Traits::int_type _Metadelim = _Traits::to_int_type(_Delim);
        typename _Traits::int_type _Meta            = _Istr.rdbuf()->sgetc();

        for (;; _Meta = _Istr.rdbuf()->snextc()) {
            if (_Traits::eq_int_type(_Traits::eof(), _Meta)) { 
                _State |= _Myis::eofbit;
                break;
            } else if (_Traits::eq_int_type(_Meta, _Metadelim)) { 
                _Changed = true;
                _Istr.rdbuf()->sbumpc();
                break;
            } else if (_Str.max_size() <= _Str.size()) { 
                _State |= _Myis::failbit;
                break;
            } else {
                _Str += _Traits::to_char_type(_Meta);
                _Changed = true;
            }
        }
        _CATCH_IO_(_Myis, _Istr)
    }

    if (!_Changed) {
        _State |= _Myis::failbit;
    }

    _Istr.setstate(_State);
    return static_cast<basic_istream<_Elem, _Traits>&>(_Istr);
}

_EXPORT_STD template <class _Elem, class _Traits, class _Alloc>
basic_istream<_Elem, _Traits>& getline(
    basic_istream<_Elem, _Traits>&& _Istr, basic_string<_Elem, _Traits, _Alloc>& _Str) {
    
    return _STD getline(_STD move(_Istr), _Str, _Istr.widen('\n'));
}

_EXPORT_STD template <class _Elem, class _Traits, class _Alloc>
basic_istream<_Elem, _Traits>& getline(
    basic_istream<_Elem, _Traits>& _Istr, basic_string<_Elem, _Traits, _Alloc>& _Str, const _Elem _Delim) {
 
    return _STD getline(_STD move(_Istr), _Str, _Delim);
}

_EXPORT_STD template <class _Elem, class _Traits, class _Alloc>
basic_istream<_Elem, _Traits>& getline(
    basic_istream<_Elem, _Traits>& _Istr, basic_string<_Elem, _Traits, _Alloc>& _Str) {
    
    return _STD getline(_STD move(_Istr), _Str, _Istr.widen('\n'));
}

_EXPORT_STD _NODISCARD inline int stoi(const string& _Str, size_t* _Idx = nullptr, int _Base = 10) {
    int& _Errno_ref  = errno; 
    const char* _Ptr = _Str.c_str();
    char* _Eptr;
    _Errno_ref      = 0;
    const long _Ans = _CSTD strtol(_Ptr, &_Eptr, _Base);

    if (_Ptr == _Eptr) {
        _Xinvalid_argument("invalid stoi argument");
    }

    if (_Errno_ref == ERANGE) {
        _Xout_of_range("stoi argument out of range");
    }

    if (_Idx) {
        *_Idx = static_cast<size_t>(_Eptr - _Ptr);
    }

    return static_cast<int>(_Ans);
}

_EXPORT_STD _NODISCARD inline long stol(const string& _Str, size_t* _Idx = nullptr, int _Base = 10) {
    int& _Errno_ref  = errno;
    const char* _Ptr = _Str.c_str();
    char* _Eptr;
    _Errno_ref      = 0;
    const long _Ans = _CSTD strtol(_Ptr, &_Eptr, _Base);

    if (_Ptr == _Eptr) {
        _Xinvalid_argument("invalid stol argument");
    }

    if (_Errno_ref == ERANGE) {
        _Xout_of_range("stol argument out of range");
    }

    if (_Idx) {
        *_Idx = static_cast<size_t>(_Eptr - _Ptr);
    }

    return _Ans;
}

_EXPORT_STD _NODISCARD inline unsigned long stoul(const string& _Str, size_t* _Idx = nullptr, int _Base = 10) {
    int& _Errno_ref  = errno; 
    const char* _Ptr = _Str.c_str();
    char* _Eptr;
    _Errno_ref               = 0;
    const unsigned long _Ans = _CSTD strtoul(_Ptr, &_Eptr, _Base);

    if (_Ptr == _Eptr) {
        _Xinvalid_argument("invalid stoul argument");
    }

    if (_Errno_ref == ERANGE) {
        _Xout_of_range("stoul argument out of range");
    }

    if (_Idx) {
        *_Idx = static_cast<size_t>(_Eptr - _Ptr);
    }

    return _Ans;
}

_EXPORT_STD _NODISCARD inline long long stoll(const string& _Str, size_t* _Idx = nullptr, int _Base = 10) {
    int& _Errno_ref  = errno;
    const char* _Ptr = _Str.c_str();
    char* _Eptr;
    _Errno_ref           = 0;
    const long long _Ans = _CSTD strtoll(_Ptr, &_Eptr, _Base);

    if (_Ptr == _Eptr) {
        _Xinvalid_argument("invalid stoll argument");
    }

    if (_Errno_ref == ERANGE) {
        _Xout_of_range("stoll argument out of range");
    }

    if (_Idx) {
        *_Idx = static_cast<size_t>(_Eptr - _Ptr);
    }

    return _Ans;
}

_EXPORT_STD _NODISCARD inline unsigned long long stoull(const string& _Str, size_t* _Idx = nullptr, int _Base = 10) {
    int& _Errno_ref  = errno; 
    const char* _Ptr = _Str.c_str();
    char* _Eptr;
    _Errno_ref                    = 0;
    const unsigned long long _Ans = _CSTD strtoull(_Ptr, &_Eptr, _Base);

    if (_Ptr == _Eptr) {
        _Xinvalid_argument("invalid stoull argument");
    }

    if (_Errno_ref == ERANGE) {
        _Xout_of_range("stoull argument out of range");
    }

    if (_Idx) {
        *_Idx = static_cast<size_t>(_Eptr - _Ptr);
    }

    return _Ans;
}

_EXPORT_STD _NODISCARD inline float stof(const string& _Str, size_t* _Idx = nullptr) {
    int& _Errno_ref  = errno;
    const char* _Ptr = _Str.c_str();
    char* _Eptr;
    _Errno_ref       = 0;
    const float _Ans = _CSTD strtof(_Ptr, &_Eptr);

    if (_Ptr == _Eptr) {
        _Xinvalid_argument("invalid stof argument");
    }

    if (_Errno_ref == ERANGE) {
        _Xout_of_range("stof argument out of range");
    }

    if (_Idx) {
        *_Idx = static_cast<size_t>(_Eptr - _Ptr);
    }

    return _Ans;
}

_EXPORT_STD _NODISCARD inline double stod(const string& _Str, size_t* _Idx = nullptr) {
    int& _Errno_ref  = errno; 
    const char* _Ptr = _Str.c_str();
    char* _Eptr;
    _Errno_ref        = 0;
    const double _Ans = _CSTD strtod(_Ptr, &_Eptr);

    if (_Ptr == _Eptr) {
        _Xinvalid_argument("invalid stod argument");
    }

    if (_Errno_ref == ERANGE) {
        _Xout_of_range("stod argument out of range");
    }

    if (_Idx) {
        *_Idx = static_cast<size_t>(_Eptr - _Ptr);
    }

    return _Ans;
}

_EXPORT_STD _NODISCARD inline long double stold(const string& _Str, size_t* _Idx = nullptr) {
    int& _Errno_ref  = errno; 
    const char* _Ptr = _Str.c_str();
    char* _Eptr;
    _Errno_ref             = 0;
    const long double _Ans = _CSTD strtold(_Ptr, &_Eptr);

    if (_Ptr == _Eptr) {
        _Xinvalid_argument("invalid stold argument");
    }

    if (_Errno_ref == ERANGE) {
        _Xout_of_range("stold argument out of range");
    }

    if (_Idx) {
        *_Idx = static_cast<size_t>(_Eptr - _Ptr);
    }

    return _Ans;
}

_EXPORT_STD _NODISCARD inline int stoi(const wstring& _Str, size_t* _Idx = nullptr, int _Base = 10) {
    int& _Errno_ref     = errno; 
    const wchar_t* _Ptr = _Str.c_str();
    wchar_t* _Eptr;
    _Errno_ref      = 0;
    const long _Ans = _CSTD wcstol(_Ptr, &_Eptr, _Base);

    if (_Ptr == _Eptr) {
        _Xinvalid_argument("invalid stoi argument");
    }

    if (_Errno_ref == ERANGE) {
        _Xout_of_range("stoi argument out of range");
    }

    if (_Idx) {
        *_Idx = static_cast<size_t>(_Eptr - _Ptr);
    }

    return static_cast<int>(_Ans);
}

_EXPORT_STD _NODISCARD inline long stol(const wstring& _Str, size_t* _Idx = nullptr, int _Base = 10) {
    int& _Errno_ref     = errno; 
    const wchar_t* _Ptr = _Str.c_str();
    wchar_t* _Eptr;
    _Errno_ref      = 0;
    const long _Ans = _CSTD wcstol(_Ptr, &_Eptr, _Base);

    if (_Ptr == _Eptr) {
        _Xinvalid_argument("invalid stol argument");
    }

    if (_Errno_ref == ERANGE) {
        _Xout_of_range("stol argument out of range");
    }

    if (_Idx) {
        *_Idx = static_cast<size_t>(_Eptr - _Ptr);
    }

    return _Ans;
}

_EXPORT_STD _NODISCARD inline unsigned long stoul(const wstring& _Str, size_t* _Idx = nullptr, int _Base = 10) {
    int& _Errno_ref     = errno; 
    const wchar_t* _Ptr = _Str.c_str();
    wchar_t* _Eptr;
    _Errno_ref               = 0;
    const unsigned long _Ans = _CSTD wcstoul(_Ptr, &_Eptr, _Base);

    if (_Ptr == _Eptr) {
        _Xinvalid_argument("invalid stoul argument");
    }

    if (_Errno_ref == ERANGE) {
        _Xout_of_range("stoul argument out of range");
    }

    if (_Idx) {
        *_Idx = static_cast<size_t>(_Eptr - _Ptr);
    }

    return _Ans;
}

_EXPORT_STD _NODISCARD inline long long stoll(const wstring& _Str, size_t* _Idx = nullptr, int _Base = 10) {
    int& _Errno_ref     = errno; 
    const wchar_t* _Ptr = _Str.c_str();
    wchar_t* _Eptr;
    _Errno_ref           = 0;
    const long long _Ans = _CSTD wcstoll(_Ptr, &_Eptr, _Base);

    if (_Ptr == _Eptr) {
        _Xinvalid_argument("invalid stoll argument");
    }

    if (_Errno_ref == ERANGE) {
        _Xout_of_range("stoll argument out of range");
    }

    if (_Idx) {
        *_Idx = static_cast<size_t>(_Eptr - _Ptr);
    }

    return _Ans;
}

_EXPORT_STD _NODISCARD inline unsigned long long stoull(const wstring& _Str, size_t* _Idx = nullptr, int _Base = 10) {
    int& _Errno_ref     = errno; 
    const wchar_t* _Ptr = _Str.c_str();
    wchar_t* _Eptr;
    _Errno_ref                    = 0;
    const unsigned long long _Ans = _CSTD wcstoull(_Ptr, &_Eptr, _Base);

    if (_Ptr == _Eptr) {
        _Xinvalid_argument("invalid stoull argument");
    }

    if (_Errno_ref == ERANGE) {
        _Xout_of_range("stoull argument out of range");
    }

    if (_Idx) {
        *_Idx = static_cast<size_t>(_Eptr - _Ptr);
    }

    return _Ans;
}

_EXPORT_STD _NODISCARD inline float stof(const wstring& _Str, size_t* _Idx = nullptr) {
    int& _Errno_ref     = errno; 
    const wchar_t* _Ptr = _Str.c_str();
    wchar_t* _Eptr;
    _Errno_ref       = 0;
    const float _Ans = _CSTD wcstof(_Ptr, &_Eptr);

    if (_Ptr == _Eptr) {
        _Xinvalid_argument("invalid stof argument");
    }

    if (_Errno_ref == ERANGE) {
        _Xout_of_range("stof argument out of range");
    }

    if (_Idx) {
        *_Idx = static_cast<size_t>(_Eptr - _Ptr);
    }

    return _Ans;
}

_EXPORT_STD _NODISCARD inline double stod(const wstring& _Str, size_t* _Idx = nullptr) {
    int& _Errno_ref     = errno; 
    const wchar_t* _Ptr = _Str.c_str();
    wchar_t* _Eptr;
    _Errno_ref        = 0;
    const double _Ans = _CSTD wcstod(_Ptr, &_Eptr);

    if (_Ptr == _Eptr) {
        _Xinvalid_argument("invalid stod argument");
    }

    if (_Errno_ref == ERANGE) {
        _Xout_of_range("stod argument out of range");
    }

    if (_Idx) {
        *_Idx = static_cast<size_t>(_Eptr - _Ptr);
    }

    return _Ans;
}

_EXPORT_STD _NODISCARD inline long double stold(const wstring& _Str, size_t* _Idx = nullptr) {
    int& _Errno_ref     = errno; 
    const wchar_t* _Ptr = _Str.c_str();
    wchar_t* _Eptr;
    _Errno_ref             = 0;
    const long double _Ans = _CSTD wcstold(_Ptr, &_Eptr);

    if (_Ptr == _Eptr) {
        _Xinvalid_argument("invalid stold argument");
    }

    if (_Errno_ref == ERANGE) {
        _Xout_of_range("stold argument out of range");
    }

    if (_Idx) {
        *_Idx = static_cast<size_t>(_Eptr - _Ptr);
    }

    return _Ans;
}

template <class _Elem, class _UTy>
_NODISCARD _Elem* _UIntegral_to_buff(_Elem* _RNext, _UTy _UVal) {
    static_assert(is_unsigned_v<_UTy>, "_UTy must be unsigned");

#ifdef _WIN64
    auto _UVal_trunc = _UVal;
#else 

    constexpr bool _Big_uty = sizeof(_UTy) > 4;
    if constexpr (_Big_uty) { 
        while (_UVal > 0xFFFFFFFFU) {
            auto _UVal_chunk = static_cast<unsigned long>(_UVal % 1000000000);
            _UVal /= 1000000000;

            for (int _Idx = 0; _Idx != 9; ++_Idx) {
                *--_RNext = static_cast<_Elem>('0' + _UVal_chunk % 10);
                _UVal_chunk /= 10;
            }
        }
    }

    auto _UVal_trunc = static_cast<unsigned long>(_UVal);
#endif 

    do {
        *--_RNext = static_cast<_Elem>('0' + _UVal_trunc % 10);
        _UVal_trunc /= 10;
    } while (_UVal_trunc != 0);
    return _RNext;
}

template <class _Elem, class _Ty>
_NODISCARD basic_string<_Elem> _Integral_to_string(const _Ty _Val) {
    static_assert(is_integral_v<_Ty>, "_Ty must be integral");
    using _UTy = make_unsigned_t<_Ty>;
    _Elem _Buff[21]; 
    _Elem* const _Buff_end = _STD end(_Buff);
    _Elem* _RNext          = _Buff_end;
    const auto _UVal       = static_cast<_UTy>(_Val);
    if (_Val < 0) {
        _RNext    = _UIntegral_to_buff(_RNext, 0 - _UVal);
        *--_RNext = '-';
    } else {
        _RNext = _UIntegral_to_buff(_RNext, _UVal);
    }

    return basic_string<_Elem>(_RNext, _Buff_end);
}


template <class _Elem, class _Ty>
_NODISCARD basic_string<_Elem> _UIntegral_to_string(const _Ty _Val) {
    static_assert(is_integral_v<_Ty>, "_Ty must be integral");
    static_assert(is_unsigned_v<_Ty>, "_Ty must be unsigned");
    _Elem _Buff[21];
    _Elem* const _Buff_end = _STD end(_Buff);
    _Elem* const _RNext    = _UIntegral_to_buff(_Buff_end, _Val);
    return basic_string<_Elem>(_RNext, _Buff_end);
}

_EXPORT_STD _NODISCARD inline string to_string(int _Val) {
    return _Integral_to_string<char>(_Val);
}

_EXPORT_STD _NODISCARD inline string to_string(unsigned int _Val) {
    return _UIntegral_to_string<char>(_Val);
}

_EXPORT_STD _NODISCARD inline string to_string(long _Val) {
    return _Integral_to_string<char>(_Val);
}

_EXPORT_STD _NODISCARD inline string to_string(unsigned long _Val) {
    return _UIntegral_to_string<char>(_Val);
}

_EXPORT_STD _NODISCARD inline string to_string(long long _Val) {
    return _Integral_to_string<char>(_Val);
}

_EXPORT_STD _NODISCARD inline string to_string(unsigned long long _Val) {
    return _UIntegral_to_string<char>(_Val);
}

_EXPORT_STD _NODISCARD inline string to_string(double _Val) {
    const auto _Len = static_cast<size_t>(_CSTD _scprintf("%f", _Val));
    string _Str(_Len, '\0');
    _CSTD sprintf_s(&_Str[0], _Len + 1, "%f", _Val);
    return _Str;
}

_EXPORT_STD _NODISCARD inline string to_string(float _Val) {
    return _STD to_string(static_cast<double>(_Val));
}

_EXPORT_STD _NODISCARD inline string to_string(long double _Val) {
    return _STD to_string(static_cast<double>(_Val));
}

_EXPORT_STD _NODISCARD inline wstring to_wstring(int _Val) {
    return _Integral_to_string<wchar_t>(_Val);
}

_EXPORT_STD _NODISCARD inline wstring to_wstring(unsigned int _Val) {
    return _UIntegral_to_string<wchar_t>(_Val);
}

_EXPORT_STD _NODISCARD inline wstring to_wstring(long _Val) {
    return _Integral_to_string<wchar_t>(_Val);
}

_EXPORT_STD _NODISCARD inline wstring to_wstring(unsigned long _Val) {
    return _UIntegral_to_string<wchar_t>(_Val);
}

_EXPORT_STD _NODISCARD inline wstring to_wstring(long long _Val) {
    return _Integral_to_string<wchar_t>(_Val);
}

_EXPORT_STD _NODISCARD inline wstring to_wstring(unsigned long long _Val) {
    return _UIntegral_to_string<wchar_t>(_Val);
}

_EXPORT_STD _NODISCARD inline wstring to_wstring(double _Val) {
    const auto _Len = static_cast<size_t>(_CSTD _scwprintf(L"%f", _Val));
    wstring _Str(_Len, L'\0');
    _CSTD swprintf_s(&_Str[0], _Len + 1, L"%f", _Val);
    return _Str;
}

_EXPORT_STD _NODISCARD inline wstring to_wstring(float _Val) {
    return _STD to_wstring(static_cast<double>(_Val));
}

_EXPORT_STD _NODISCARD inline wstring to_wstring(long double _Val) {
    return _STD to_wstring(static_cast<double>(_Val));
}
_STD_END

#pragma pop_macro("new")
_STL_RESTORE_CLANG_WARNINGS
#pragma warning(pop)
#pragma pack(pop)
#endif 
#endif 
