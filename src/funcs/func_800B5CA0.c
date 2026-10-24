/* compiler: cc1plus */
/* cflags: -O2 */
#include "common.h"

extern "C" s32 func_800B713C(void *, s32);
extern "C" void func_800B7154(void *, void *, u8 *);
extern "C" void func_800B7160(void *, void *);
extern "C" void func_800B720C(void *, s32);
extern "C" s32 **func_800B75DC(void *);
extern "C" void func_800B70EC(void *);
extern "C" void func_800B7620(void *, const void *);

struct Reader {
    s32 *hdr;
    u8 *base;
    Reader(void *p) { func_800B7160(this, p); }
    Reader(void *p, u8 *b) { func_800B7154(this, p, b); }
    s32 count() { return *hdr; }
    s32 offset(s32 i) { return func_800B713C(this, i); }
    u8 *get(s32 i) { return base + offset(i); }
    s32 size(s32 i) { return offset(i + 1) - offset(i); }
};

struct Writer {
    u8 state[0x18];
    ~Writer() { func_800B720C(this, 2); }
    s32 **data() { return func_800B75DC(this); }
    void append(Writer &src, s32 flag);
};

/* out-of-line Writer members: init, put, finish */
extern "C" void func_800B71C8(Writer *);
extern "C" void func_800B72C8(Writer *, void *, s32, s32, s32);
extern "C" s32 func_800B7460(Writer *, s32, s32);

inline void Writer::append(Writer &src, s32 flag) {
    s32 *res = *src.data();
    s32 n = res[res[0] + 1];
    func_800B72C8(this, res, n, flag, 8);
}

struct Vec3 {
    f32 x, y, z;
};

struct Bounds {
    Vec3 min;
    Vec3 max;
};

struct Box : Bounds {
    s32 empty;
    Box() { func_800B70EC(this); }
    void add(const Vec3 &v) { func_800B7620(this, &v); }
};

struct Ent {
    Bounds bounds;
    f32 unk18;
    f32 unk1C;
};

struct Obj {
    s32 *unk0;
    s32 unk4;
    Bounds bounds;
    f32 unk20;
    f32 unk24;
};

struct Arc {
    s32 *hdr;
    u8 *base;
    u8 pad8[4];
    u8 unkC[4];
    void unpack(u8 *src, s32 len, void *dst);
};

extern "C" void *func_8009B898(Arc *, s32, s32);
extern "C" void *func_8009E6B4(u8 *, s32, s32);
extern "C" void *func_8009E8F0(u8 *, s32, s32);
extern "C" void func_8009ECF8(u8 *, void *);
extern "C" void func_800B2CF0(void *, u8 *, s32, void *);
extern "C" void func_800B5A4C(void);
extern "C" void func_800B6278(Obj *);
extern "C" void func_800B6280(Obj *);
extern "C" void func_800B6758(Obj *);
extern "C" s32 func_800B68D0(Obj *, u8 *);
extern "C" void func_800B695C(Obj *, u8 *, void *);
extern u8 D_800EA110[];
extern Arc D_800ECFE0;

inline void Arc::unpack(u8 *src, s32 len, void *dst) {
    func_800B2CF0(unkC, src, len, dst);
}

extern "C" void func_800B5CA0(Obj *obj, s32 id) {
    func_800B5A4C();
    Box box;
    obj->unk20 = obj->unk24 = 0.0f;
    void *data = func_8009B898(&D_800ECFE0, id, -1);
    if (data != NULL) {
        Reader top(data, D_800ECFE0.base + func_800B713C(&D_800ECFE0, id));
        obj->unk4 = top.count();
        obj->unk0 = (s32 *)func_8009E6B4(D_800EA110, obj->unk4 * 4, 4);
        if (obj->unk0 != NULL) {
            for (s32 i = 0; i < obj->unk4; i++) {
                u8 *p = top.get(i);
                s32 len = top.size(i);
                u8 *buf = (u8 *)func_8009E8F0(D_800EA110, len, 8);
                if (buf != NULL) {
                    D_800ECFE0.unpack(p, len, buf);
                    Reader r1(buf);
                    Writer w1;
                    func_800B71C8(&w1);
                    Ent *ent = (Ent *)r1.get(0);
                    box.add(ent->bounds.min);
                    box.add(ent->bounds.max);
                    obj->unk20 = (ent->unk18 < obj->unk20) ? obj->unk20 : ent->unk18;
                    obj->unk24 = (ent->unk1C < obj->unk24) ? obj->unk24 : ent->unk1C;
                    func_800B72C8(&w1, r1.get(0), r1.size(0), 0, 8);
                    Reader r2(r1.get(1));
                    Writer w2;
                    func_800B71C8(&w2);
                    s32 n = r2.count();
                    for (s32 j = 0; j < n; j++) {
                        Reader r3(r2.get(j));
                        Writer w3;
                        func_800B71C8(&w3);
                        u8 *e = r3.get(0);
                        func_800B72C8(&w3, e, r3.size(0), 0, 8);
                        if (((s32 *)e)[1] & 0x8000) {
                            func_800B72C8(&w3, r3.get(1), r3.size(1), 0, 8);
                            func_800B72C8(&w3, r3.get(2), r3.size(2), 0, 8);
                            w2.append(w3, 1);
                        } else {
                            u8 *q = r3.get(1);
                            s32 qlen = func_800B68D0(obj, q);
                            void *tmp = func_8009E8F0(D_800EA110, qlen, 8);
                            func_800B695C(obj, q, tmp);
                            func_800B72C8(&w3, tmp, qlen, 0, 8);
                            func_800B72C8(&w3, r3.get(2), r3.size(2), 0, 8);
                            w2.append(w3, 1);
                            func_8009ECF8(D_800EA110, tmp);
                        }
                    }
                    w1.append(w2, 0);
                    func_800B72C8(&w1, r1.get(2), r1.size(2), 0, 8);
                    obj->unk0[i] = func_800B7460(&w1, 0, 8);
                    func_8009ECF8(D_800EA110, buf);
                }
            }
        }
        func_8009ECF8(D_800EA110, data);
        if (obj->unk0 != NULL) {
            func_800B6758(obj);
            func_800B6280(obj);
        }
    }
    obj->bounds = box;
    func_800B6278(obj);
}
