/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include <memory.h> /* for memset */
#include "calculadora.h"

/* Default timeout can be changed using clnt_control() */
static struct timeval TIMEOUT = { 25, 0 };

resultado_calculadora *
operacion_aritmetica_1(operacion arg1,  CLIENT *clnt)
{
	static resultado_calculadora clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, OPERACION_ARITMETICA,
		(xdrproc_t) xdr_operacion, (caddr_t) &arg1,
		(xdrproc_t) xdr_resultado_calculadora, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

resultado_calculadora *
operacion_trigonometrica_2(operacion_t arg1,  CLIENT *clnt)
{
	static resultado_calculadora clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, OPERACION_TRIGONOMETRICA,
		(xdrproc_t) xdr_operacion_t, (caddr_t) &arg1,
		(xdrproc_t) xdr_resultado_calculadora, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

resultado_calculadora_ecuaciones *
operacion_ecuaciones_3(operacion_e arg1,  CLIENT *clnt)
{
	static resultado_calculadora_ecuaciones clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, OPERACION_ECUACIONES,
		(xdrproc_t) xdr_operacion_e, (caddr_t) &arg1,
		(xdrproc_t) xdr_resultado_calculadora_ecuaciones, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

resultado_calculadora_vectores *
operacion_vectores_4(operacion_v arg1,  CLIENT *clnt)
{
	static resultado_calculadora_vectores clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, OPERACION_VECTORES,
		(xdrproc_t) xdr_operacion_v, (caddr_t) &arg1,
		(xdrproc_t) xdr_resultado_calculadora_vectores, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}